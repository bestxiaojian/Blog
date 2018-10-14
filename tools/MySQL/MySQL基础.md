# MySQL基础

docker方式连接本地mysql:

1. 下载mysql docker image: docker pull mysql
2. docker run --name wangjian10_mysql -p 9091:3306 -e MYSQL_ROOT_PASSWORD=123456 -d mysql
3. docker exec -it constainerID bash

### SQL分类

- 数据查询语言（DQL-data query language）

  代表关键字：select

- 数据操纵语言（DML-data Manipulation language）

  代表关键字：insert delete update

- 数据定义语言（DDL -data definition language）（针对表的结构）

  代表关键字：create，drop，alter

- 事务控制语言（TCL- transactional control language）

  代表关键字：commit， rollback

- 数据控制语言（DCL-data control language）

  代表关键字：grant，revoke

### 基本命令

1. 创建数据库

   create database + 名称

2. 使用某个数据库

   use + 数据库名称

3. 删除数据库

   drop database + 数据库名称

4. 查看某个数据库下有哪些表格

   show tables

5. 查看某个表的表结构，即有哪些字段等

   desc + 表名称

6. 查看有哪些数据库

   show databases

7. 查看当前使用的数据库

   select database()

8. 查看某个表创建时候是如何创建的

   show create table + 表名称

### 查询语句： select

select 语句不会改变表中的数据，只是查询检索出来

- 查询表格中为空的情况用：is null，例如：

  select ename , comm from emp **where** comm **is null**;

- 不是空的话：is not null 即可，例如：

  select ename , comm from emp **where** comm **is not null**;

- and和or 同时存在的情况下，and的优先级高于or

  也可以直接使用括号区分出来优先级哈

- 模糊查询：**like**

  0~无穷多个任意字符：%   例如：

  select ename from emp where ename like '%T%'   (表示ename中含有字符T的)

- 下划线代表任意一个字符：例如：

  select ename from emp where ename like '_A%'     (表示ename中第二个字符是Ａ的)

-  排序：order by + 字段　（desc)
- 











