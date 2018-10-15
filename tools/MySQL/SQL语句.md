# SQL语句

**SQL语句对大小写不敏感**

可以把SQL分为两个部分：数据操作语言（DML）和数据定义语言（DDL）

数据操作语言主要包括：增删改查

- **SELECT** - 从数据库表中获取数据
- **UPDATE** - 更新数据库表中的数据
- **DELETE** - 从数据库表中删除数据
- **INSERT INTO** - 向数据库表中插入数据

SQL中最重要的DDL语句：

- **CREATE DATABASE** - 创建新数据库
- **ALTER DATABASE** - 修改数据库
- **CREATE** **TABLE** - 创建新表
- **ALTER TABLE** - 变更（改变）数据库表
- **DROP TABLE** - 删除表
- **CREATE INDEX** - 创建索引（搜索键）
- **DROP INDEX** - 删除索引

### SQL基础

- SQL select语句

  ```SQL
  SELECT 列名称 FROM 表名称    或者
  SELECT * FROM 表名称  （选取表中所有列）
  ```

- SQL SELECT DISTINCT语句

  在表中，某一列可能包含重复值，有时候仅仅希望列出不同的值，此时需要使用select distinct语句

  ```Sql
  SELECT DISTINCT 列名称 FROM 表名称
  ```

- WHERE 语句

  **如需有条件的从表中选取数据，可将WHERE语句添加到SELECT语音中**

  ```SQL
  SELECT 列名称 FROM 表名称 WHERE 列 运算符 值
  ```

  其中运算符包括=， <>，<，>，<=，>=，BETWEEN（在某个范围内），LIKE（搜索某种模式）

  例如：

  ```sql
  SELECT * FROM Persons WHERE city='beijing'
  ```

     (文本值用单引号括起来，大部分系统双引号也可以)

- SQL AND OR 运算符

  用于一个以上的条件对记录进行过滤，AND即为且，OR即为或者哈

  例如：

  ```SQL
  SELECT * FROM Persons WHRER FirstName='Tomas' AND LastName='Carter'
  ```

- ORDER BY 语句

  用于根据指定的列对结果集进行排序（默认按照升序进行排序），如果希望降序排序，使用**DESC**关键字

  ```SQL
  SELECT Company,OrderNum FROM Orders ORDER BY Company DESC
  ```

- INSERT INTO 语句

  **用于向表格中插入新的行**

  ```sql
  INSERT INTO 表名称 VALUES (值1，值2，......) 
  我们也可以指定所要插入数据的列
  INSERT INTO 表名称 （列1，列2......) VALUES (值1，值2......)
  ```

  例如：

  ```SQL
  INSERT INTO Persons VALUES ('Gates','Bill','Xuanwumen 10','Beijing')
  或者
  INSERT INTO Persons (LastName,Address) VALUES ('Wilson','Champs-Elysees')
  ```

- SQL UPDATE语句用于修改表中的数据

  语法：

  ```SQL
  UPDATE 表名称 SET 列名称 = 新值 WHERE 列名称 = 某值
  ```

  例如：

  ```SQL
  UPDATE Persons SET Firstname = 'Fred' WHERE Lastname = 'Wilson'
  ```

- SQL DELETE 语句

  **DELETE语句用于删除表中的行**

  语法：

  ```sql
  DELETE FROM 表名称 WHERE 列名称 = 值
  ```

  **删除所有行**：可以在不删除表的情况下删除所有的行。**这意味着表的结构、属性和索引都是完整的**：

  ```SQL
  DELETE * FROM 表名称   或者
  DELETE FROM 表名称
  ```

- SQL CREATE DATABASE 语句

  **用于创建数据库**

  语法：

  ```SQL
  CREATE DATABASE 数据库名称 
  ```

  例如：创建名为mydb的数据库

  ```SQL
  CREATE DATABASE mydb
  ```

- SQL CREATE TABLE 语句

  **用于创建数据库中的表**

  语法：

  ```SQL
  CREATE TABLE 表名称
  （
  列名称1 数据类型，
  列名称2 数据类型，
  列名称3 数据类型，
  ......
  ）
  ```

  数据类型规定了列可容纳何种数据类型：

  **int(size)/integer(size)**  :  仅容纳整数，括号内规定数字的最大位数

  **decimal(size,d)/numeric(size,d)** : 容纳带有小数的数字，"size"规定的数字的最大位数，"d"规定小数点右侧的最大位数

  **char(size)**：容纳固定长度的字符串，括号中规定字符串的长度

  **varchar(size)**：容纳可变长度的字符串，括号中规定字符串的最大长度

  **date(yyyymmdd)**：容纳日期

  例如：

  ```SQL
  CREATE TABLE Persons
  (
  Id_P int,
  Lastname varchar(255),
  Firstname varchar(255),
  Address varchar(255),
  City varchar(255)
  )
  ```

  

























