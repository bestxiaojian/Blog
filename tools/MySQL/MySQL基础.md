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

- 排序：order by + 字段　（asc，desc)　：　例如，多字段排序：select ename,sal from emp order by sal desc, ename asc;

- 基本处理函数ifnull，upper，lower，trim，rand()，round()，substr()

- **Mysql中的日期处理**

  １．不同的数据库处理日期的时候，采用的机制是不同的，日期处理都有自己的一套机制。所以在实际的开发中，表中的字段定义为DATE类型，这种情况很少。在实际开发中，**会使用“日期字符串”来表示日期**。

  ２．MySql数据库管理系统中对日期的处理提供了两个重要的函数：str_to_date和date_format

  - **str_to_date**：该函数的作用是将日期字符串转换成日期类型数据【varchar --> date】
  - 该函数的使用方式：**str_to_date('日期字符串','日期格式')**
  - Mysql中的日期格式：％Y, %m,%d,%h,%i,%s 即年，月，日，时，分，秒
  - Mysql中默认的日期格式：**%Y-%m-%d**，例如　select ename,hiredate from emp where hiredate=str_to_date('1987-12-12', '%Y-%m-%d')
  - **date_format**：该函数作用：将日期类型date转换成具有特定格式的日期字符串varchar【date --> varchar】
  - 该函数的语法形式：date_format(日期类型数据,　'日期格式')
  - 小结：str_to_date主要使用在插入操作中，而date_format主要使用在查询操作中，即客户需要日期以特定格式展示的时候

- 分组函数/聚合函数/多行处理函数：注意这些函数自动忽略空值（ＮＵＬＬ），不需要再用where去判断空值了哈

  １．sum:求和

  ２．max/min：求最大和最小

  ３．avg:求平均

  ４．count：求个数

  例如：select count(comm) from emp; 

  但是，**以上分组函数不能使用在where子句中！**　　例如：select ename,sal from emp where sal > avg(sal);　是错误的

  select count(*) from emp where xxx : 　**符合条件的所有记录总数**

  select count(comm) from emp : 　**comm这个字段不为空的元素总数**

- **去除重复的**关键字是distinct：必须用在所有字段的最前面；例如：　select distinct job from emp;

### 分组查询

- 分组查询涉及到的两个子句是：1. **group by** 2. **having**

### 连接查询

- 实际开发中，数据并不是存放在一张表中；从多张表中查询数据，又称为多表查询

- 连接查询根据查询方式分为：

  - 内连接：**两张表中能够匹配的内容查询出来**；

     	1. 等值连接
     	2. 非等值连接
     	3. 自连接：在一张表中进行匹配；

  - 外连接：**在内连接显示内容基础上，把其中一张表的内容无条件全部显示出来**

    外连接的查询结果条数 >= 内连接的查询结果条数;

    任何一个右外连接可以写成一个左外连接，任何一个左外连接同样可以写成一个右外连接；

    例如：

    ```SQL
    select e.ename,d.dname from emp e right join dept d on e.deptno=d.deptno;
    select e.ename,d.dname from dept d left join emp e on e.deptno=d.deptno;
    ```



    1. 左外连接（又叫左连接）关键字：**left join**
    2. 右外连接（右连接）:  关键字：**right join**

  - 全连接【几乎不用，不介绍】

- 小知识点：在进行多表连接查询的时候，尽量给表起别名，这样效率高，可读性高。

- 当多张表进行连接查询，若没有任何条件进行限制，会发生什么现象：笛卡尔现象，一张表的记录会和另外一张表的所有记录进行匹配，而最终查询记录总数是两张表查询记录的乘积；

- 例如如下两张表：

- +-----------+---------+------+-----+---------+-------+
  | Field     | Type    | Null | Key | Default | Extra |
  +-----------+---------+------+-----+---------+-------+
  | emp_no    | int(11) | NO   | PRI | NULL    |       |
  | dept_no   | char(4) | NO   | PRI | NULL    |       |
  | from_date | date    | NO   |     | NULL    |       |
  | to_date   | date    | NO   |     | NULL    |       |
  +-----------+---------+------+-----+---------+-------+

  +-----------+-------------+------+-----+---------+-------+
  | Field     | Type        | Null | Key | Default | Extra |
  +-----------+-------------+------+-----+---------+-------+
  | dept_no   | char(4)     | NO   | PRI | NULL    |       |
  | dept_name | varchar(40) | NO   | UNI | NULL    |       |
  +-----------+-------------+------+-----+---------+-------+

```sql
SQL-92语法，内连接中的等值连接：
select de.emp_no,d.dept_name from dept_emp de,departments d where de.dept_no=d.dept_no;
SQL-99语法，内连接中的等值连接：join on语法，使得表连接从where中独立出来
select de.emp_no,d.dept_name from dept_emp de join departments d on de.dept_no=d.dept_no;
```

