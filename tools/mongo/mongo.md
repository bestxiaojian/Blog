# Mongo

### 基本概念

mongo中包括如下概念：

1. 数据库
2. 集合(collections)
3. 文档/数据记录行(document)
4. 数据字段/域(field)
5. 索引(index)

### 数据库

一个mongo中可以建立多个数据库

**show dbs**可以显示所有数据库的列表

- **创建数据库**通过如下命令：

  use DATABASE_NAME

  如果数据库不存在，则创建数据库，否则切换到指定数据库

  mongo中默认的数据库为test，如果没有创建新的数据库，集合将存放在test数据库中

- **删除数据库**的语法如下：

  db.dropDatabase()

  此条命令会删除当前数据库，可以使用db命令查看当前数据库名

  

### 集合

集合就是文档组，集合存在于数据库中，当第一个文档插入时，集合就会被创建

- **创建集合**

  db.createCollection(name, options)

  参数说明：

  name: 要创建的集合名称

  options:可选参数，指定有关内存大小及索引的选项

  如：db.createCollection("runoob")

- **查看已有集合**

  show collections 或者  show tables

- **查看集合中文档个数**

  db.collection名字.count()

- **删除集合**

  可以先通过show collections命令查看已存在的集合，然后通过如下命令删除集合：

  **db.collection名字.drop()**

  

### 文档

文档就是**数据记录的一行**，是一组键值对儿

所有存储在集合中的数据都是BSON格式，BSON是一种类json的一种二进制形式的存储格式，简称Binary JSON

- 插入文档

  mongo中使用insert或者save方法向集合中插入文档，语法如下：

  db.COLLECTION_NAME.insert(document)

  注意，如果collection_name不在该数据库中，mongo会自动创建集合并插入文档，所以可以通过此方法直接创建集合

- **查看已插入的文档**

  **db.collection_name.find()**

- **删除文档**

  db.collection_name.remove(

  ​	<query>,

  ​	{

  ​		justOne: <boolean>

  ​		writeConcern: <document>

  ​	}

  )

  参数说明：

  query: (可选) 删除的文档的条件

  justOne: (可选)  如果设为true或者1，则只删除一个文档

  writeConcern: (可选) 抛出异常的级别

  

