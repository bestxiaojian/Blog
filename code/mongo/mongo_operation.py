#!/usr/bin/python
# -*- coding: utf-8 -*-

from pymongo import MongoClient
import xlrd
import sys
import json
import os

#自己docker中mongoexport可执行文件路径
mongoexport_path = "/data/wangjian10_baseline/extra_home/wangjian10/mongodb/mongodb-linux-x86_64-rhel62-3.4.17/bin/mongoexport"
parameters = " --host 127.0.0.1 --port 27017 -u work -p work -d testdb -c kideducation --type=json -o kidedu.csv"
exportCmd = mongoexport_path + parameters

db = None
#1. 连接testdb数据库
def ConnectMongo():
	global db
	client = MongoClient("127.0.0.1",27017)
	db = client.testdb
	db.authenticate("work","work")

#2. 读取sheet表数据
def Main():
	global db
	if len(sys.argv) != 3:
		print "Sorry,parameter error,need 2 parameters after .py file :"
		print "1) xls file name 2) operation: insert,delete or export"
		sys.exit(0)
	file_name = sys.argv[1]
	operation = sys.argv[2]

	if operation == "insert":
		bookdata = xlrd.open_workbook(file_name)
		sheet1 = bookdata.sheet_by_name(u"识图")
		sheet2 = bookdata.sheet_by_name(u"识字")
		sheet3 = bookdata.sheet_by_name(u"诗词")


		#3. 数据库设计字段
		tags = ["qid","level","question","selection","answer","answerText"]

		#4. 拼接sheet1页（识图）内容并插入到mongo中
		# qid从1000开始，识图系列level = 1
		# 对于识图系列，answer表示正确选项序号：1或2，answerText表示对应正确选项图片url或者id
		returnData = {}
		current_num = db.kideducation.count_documents({})
		qid = "1000"
		level = "1"
		for i in range(1,sheet1.nrows):
			question = sheet1.cell(i,1).value
			#对应excel表格中自己增加的selection_id1列，即选项1
			selection_id1 = sheet1.cell(i,6).value 
			#对应excel表格中自己增加的selection_id2列，即选项2
			selection_id2 = sheet1.cell(i,7).value 
			selection = [selection_id1,selection_id2]
			#对应excel中自己增加的answer列
			answer = sheet1.cell(i,8).value
			answer = int(answer) 
			index = answer - 1
			answerText = selection[index]
			answer = str(answer)
			#拼接
			line_content = [qid,level,question,selection,answer,answerText]
			returnData[i] = json.dumps(dict(zip(tags,line_content)))
			returnData[i] = json.loads(returnData[i])
			db.kideducation.insert_one(returnData[i])
			qid = str(int(qid) + 1)

		#拼接sheet2页（识字），qid从2000开始，level = 2
		#识字系列没有选项，所以只提供正确的读音answer = 1,selection只有一项
		#answerText为正确答案
		qid = "2000"
		level = "2"
		for i in range(1,sheet2.nrows):
			question = sheet2.cell(i,1).value
			answer = "1"
			answerText = sheet2.cell(i,5).value
			selection = [answerText]
			line_content = [qid,level,question,selection,answer,answerText]
			returnData[i] = json.dumps(dict(zip(tags,line_content)))
			returnData[i] = json.loads(returnData[i])
			db.kideducation.insert_one(returnData[i])
			qid = str(int(qid) + 1)

		#拼接sheet3页（诗词）,answer为正确答案选项（1或2），answerText为正确诗词
		qid = "3000"
		level = "3"
		for i in range(1,sheet3.nrows):
			question = sheet3.cell(i,1).value
			selection_id1 = sheet3.cell(i,6).value
			selection_id2 = sheet3.cell(i,7).value
			selection = [selection_id1,selection_id2]
			answer = sheet3.cell(i,8).value
			answer = int(answer)
			index = answer - 1
			answerText = selection[index]
			answer = str(answer)
			line_content = [qid,level,question,selection,answer,answerText]
			returnData[i] = json.dumps(dict(zip(tags,line_content)))
			returnData[i] = json.loads(returnData[i])
			db.kideducation.insert_one(returnData[i])
			qid = str(int(qid) + 1)
		to_insert_num = sheet1.nrows + sheet2.nrows + sheet3.nrows -3 #每个sheet表第一行不计算
		inserted_num = db.kideducation.count_documents({}) - current_num
		if inserted_num == to_insert_num:
			print "insert operation successfully,inserted num : %d" %(inserted_num)
		else:
			print "insert operation error,inserted num: %d, to insert num : %d" %(inserted_num,to_insert_num)
	elif operation == "delete":
		db.kideducation.drop()
	elif operation == "export":
		os.system(exportCmd)
	else:
		print "Unknown operation !"

if __name__ == "__main__":
	ConnectMongo()
	Main()
