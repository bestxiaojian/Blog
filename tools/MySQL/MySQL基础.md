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

8. 查**看某个表创建时候是如何创建的**

   **show create table + 表名称**;

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

- **SQL99语法优点：表连接独立出来了，结构更清晰。对表连接不满意的话，可以再追加where进行过滤**

- 自连接就是一张表“看成”两张表

  ```sql
  select a.ename empname,b.ename leadername from emp a join emp b on a.mgr=b.empno;
  或者
  select a.ename empname,b.ename leadername from emp a,emp b where a.mgr=b.empno;
  ```

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

### 排序数据

排序数据用order by，默认是升序；

```sql

```

**多字段排序**：用逗号隔开各个字段，后面的字段可能用不上，即如果前面的字段根本没有相同的值，则后面的字段排序根本用不上了

```sql
select ename,sal from emp order by sal desc,ename asc;
```

如上SQL就是表示按照工资降序排序，工资相同的情况下，按照名字升序排列

### **事务**(Transaction)

​	事务是一个最小的不可再分的工作单元

​	通常一个事务对应了一个完整的业务，而一个完整的业务需要批量的DML语句（insert，update，delete）共同联合完成。事务**只和DML语句**有关系，或者说DML语句才有事务。

 事务的四个特性：

 	1. 原子性：事务是最小的工作单元，不可再分
 	2. 一致性：事务要求所有的DML语句操作的时候，必须保证同时成功或者同时失败
 	3. 隔离性：事务A和事务B之间具有隔离
 	4. 持久性： 是事务的保证，事务终结的标志（内存中的数据持久到硬盘文件中）

**和事务有关的两条重要SQL语句：**

 	1. commit;            提交
 	2. rollback；         回滚

事务开启的标志是什么？事务结束的标志是什么？

1. 开启的标志：任何一条DML语句的执行，标志事务的开始。

2. 结束的标志：提交或者回滚

   提交：成功的结束，将所有的DML语句操作历史记录和底层硬盘文件中的数据来一次同步

   回滚：失败的结束，将所有的DML语句操作历史记录全部清空

**重点**：在事务进行的过程中，未结束之前，DML语句是不会更改底层数据库文件中的数据。只是将历史操作记录一下，在内存中完成记录。只有在事务结束的时候，而且是成功结束的时候才会修改底层硬盘文件中的数据。

**在MYSQL数据库管理系统中，默认情况下，事务是自动提交的。也就是说，只要执行一条DML语句，开启了事务，并且提交了事务。**

- 这种自动提交的机制是可以关闭的：（关闭的一种方式，还有其他方式）

  start transaction;     手动开启事务

  DML语句...

  DML语句...

  DML语句...

  commit;        手动提交事务（事务成功的结束）

- start transaction;      手动开启事务

  DML语句...

  DML语句...

  DML语句...

  rollback;       手动回滚事务（事务失败的结束）

关闭自动提交的第二种方式：

- set autocommit = off;
- 或者 set session autocommit = off;

打开自动提交：

- set autocommit = on;
- 或者set session autocommit = on;

以上修改方式只对当前会话有效

### 事务四个特性之一：**隔离性**

- 事务A和事务B之间具有一定的隔离性
- 隔离性有隔离级别（4个）：
  - read uncommited 读未提交
  - read commited 读已提交
  - reapeatable read 可重复读
  - serializable 串行化
- read uncommitted 读未提交
  - 事务A和事务B，事务A未提交的数据，事务B可以读取到。
  - 这里读取到的数据可以叫做“脏数据”或者叫做“dirty Read”
  - 这种隔离级别是最低级别，这种级别一般都是在理论上存在的，数据库默认的隔离级别一般都是高于该隔离级别的。
- read committed 读已提交
  - 事务A和事务B，事务A提交的数据，事务B才能读取到。
  - 这种隔离级别高于上面的读未提交
  - 换句话说，对方事务提交之后的数据，当前事务才能读取到
  - 这种隔离级别可以避免脏数据
- repeatable read 可重复读
  - 事务A和事务B，事务A提交之后的数据，事务B读取不到
  - 事务B是可重复读取数据的
  - 这种隔离级别高于读已提交，换句话说，对方提交之后的数据我还是读取不到
  - 这种隔离级别可以避免“脏读和不可重复读取”，达到可重复读取
  - **MYSQL数据库管理系统默认的隔离级别就是：可重复读取**
  - 虽然可以达到“可重复读“的效果，但是会导致”幻象读”
- serializable   串行化
  - 事务A和事务B，事务A在操作数据库表中数据的时候，事务B只能排队等待
  - 这种事务隔离级别一般很少使用，吞吐量太低，用户体验不好
  - 这种隔离级别可以避免“幻象读”，每一次读取的都是数据库表中真实的记录
  - 事务A和事务B不再并发

### 设置事务的隔离级别

- 第一种方式: 修改my.ini配置文件

  [mysqld]

  transaction-isolation = READ-COMMITTED

  可选址：

  - READ-UNCOMMITTED
  - READ-COMMITTED
  - REPEATABLE-READ
  - SERIALIZABLE

- 第二种方式：使用命令方式设置事务的隔离级别

  - 命令格式：set <无/session/global] transaction isolation level <isolation-level>;

  - 可选址：

    READ UNCOMMITTED

    READ COMMITTED

    REPEATABLE READ

    SERIALIZABLE

  设置事务的隔离级别作用于全局：set global transaction isolation level <level>;

  设置事务的隔离级别作用于当前会话：set transaction isolation level <level>;或者

  set session transaction isolation level <level>;

### 查看隔离级别

- 查看当前会话的隔离级别：select @@tx_isolation;   或者   select @@session.tx_isolation;

- 查看全局的事务隔离级别：

  select @@ global.tx_isolation;

### 几种隔离级别的演示：

- 读未提交；

  会话1                                                                                                               会话2

  **set  global transaction isolation level read uncommitted**

  **exit**

  **use  +  database;                                                                          use + database;**

  **start transaction;                                                                     start transaction;**

  **insert into t_user(name) values("king")                         select * from t_user;**

- 读已提交

  会话1                                                                                                           会话2

  **set global transaction isolation level read committed**

  **exit**

  **use + database;                                                                           use + database;**

  **start transaction;                                                 start transaction;**

  **insert into t_user(name) values("ford");                      select * from t_user;**

  **commit;                                                                              select * from t_user;**

- 重复读

  会话1                                                                                                      会话2

  **set global transaction isolation level repeatable read;**

  **use + database;                                                          use + database;**

  **start transaction;                                                start transaction;**

  **insert into t_user(name) values("luzhishen");**

  **commit;                                                             select * from t_user;**

### **视图**

创建视图：create view + 视图名 as ...

比如：create view myview as select * from emp;

视图是一种根据查询（也就是select表达式）定义的数据库对象，用于获取想要看到和使用的局部数据

- 视图有时也被称为“虚拟表”
- 相对于从基表中直接获取数据，视图有以下好处：
  - 访问数据变得简单
  - 可被用来对不同用户显示不同的表的内容

### **数据库设计三准则**

1. **要求有主键，并且要求每一个字段原子性不可再分**
2. **要求所有非主键字段完全依赖主键，不能产生部分依赖**
3. **所有非主键字段和主键字段之间不能产生传递依赖**

### **几个比较经典的设计**

1. 一对一：两种方案：
   - **第一种方案：分两张表存储，共享主键**
   - **分两张表存储，外键唯一**
2. 一对多：**分两张表存储，在多的一方添加外键，这个外键字段引用一的一方中的主键字段**
3. 多对多：**分三张表存储，在学生表中存储学生信息，在课程表中存储课程信息，在学生选课表中存储学生和课程的关系信息**

实际开发中是怎样的?

- **注意：数据库设计尽量遵循三准则**
- **但是还是根据实际情况进行取舍**
- **有时可能会拿冗余换速度，最终目的要满足客户需求**

### **索引**（index）

什么是索引？

- 索引相当于一本字典的目录，索引的作用是提高程序的检索（查询）效率
- 主键是自动添加索引的，所以能通过主键查询尽量通过主键查询，效率较高
- 索引和表相同，都是一个对象，表是存储在硬盘文件中的，那么索引是表的一部分，索引也是存储在硬盘文件中

在MYSQL数据库管理系统中，对表中记录进行索引的时候，通常包括几种检索方式：

- 第一种：全表扫描（**效率较低**）

  比如：假设有一张表：emp 员工表

  select * from emp where ename="KING";

  若ename字段上没有添加索引，那么在通过ename字段过滤数据的时候，ename字段会被全部扫描

- 第二种方式：通过索引进行检索（**提高查询效率**）

**一张表中有多个字段的话，每一个字段都是可以添加索引的。**

**什么情况下适合给表中的某个字段添加索引呢？**

- **该字段数据量庞大**（一般客户反馈有点慢时，考虑添加索引看看）
- **该字段经常出现在where条件当中**
- **该字段很少的DML操作（DML操作很多的话，索引也是需要不断维护的，此时加索引效率反而降低）**

**怎么创建和删除索引？**

- 创建索引：create index 索引名 on 表名（字段名）;

  比如：create index dept_dname_index on dept(dname);

- 删除索引：drop index 索引名 on 表名;

  比如：drop index dept_dname_index on dept;

### **子查询**

什么是子查询？

- **select语句嵌套select语句**

子查询可以出现在哪？

- select ...(select)

  from ... (select)

  where ... (select)

**案例：**

1. 找出薪水比公司平均薪水高的员工，要求显示员工名和薪水

**select ename,sal from emp where sal > avg(sal); 是错误的！！！** 因为分组函数avg不能直接使用在where语句后面。

正确方法：

- 第一步：找出公司的平均薪水： select avg(sal) from emp;
- 第二步：找出薪水大于平均薪水的员工信息： **select ename,sal from emp** **where sal > (select avg(sal) from emp);**

2. from后面加select例子：**（小窍门：将查询结果作为临时表 t)**

   找出每个部门的平均薪水，并且要求显示平均薪水的薪水等级

   - 第一步：找出每个部门的平均薪水：

     select deptno,avg(sal) as avgsal from emp group by deptno;

   - 将上面的查询结果当做临时表t,t表和salgrade s表进行表连接，条件：t.avgsal between s.losal and s.hisal;

   即:

   select 

   ​	t.deptno,t.avgsal,s.grade 

   from 

   ​	**t** 

   join 

   ​	salgrade s 

   on 

   ​	t.avgsal between s.losal and s.hisal;

   ​             c.将临时表t换成a步骤中SQL语句的结果即：

   select 

   ​	t.deptno,t.avgsal,s.grade

   from 

   ​	**(select deptno,avg(sal) as avgsal from emp group by deptno) t**

   join

   ​	salgrade s

   on 

   ​	t.avgsal between s.losal and s.hisal;

   以上结果即为所求；




