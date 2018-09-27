# docker基础

### docker解决的问题

开发和部署时，因为环境等配置问题，会产生很多问题。在传统时候，可能开发时运行一点问题没有，可在部署时候因为环境等差异，出现各种问题，此时docker应运而生。

docker思想：软件和相关运行环境打包安装，这样可消除“在我的机器上可正常运行”的问题，“一次构建，处处运行”

### docker是什么

解决了运行环境和配置问题的软件容器，方便做持续集成并有助于整体发布的容器虚拟化技术

docker官网：www.docker.com

docker中文网：www.docker-cn.com

docker HUB: hub.docker.com

### docker基本组成

三大组件：镜像、容器、仓库

- 镜像：docker镜像就是一个只读模板，镜像可以用来创建docker容器，**一个镜像可以创建多个容器**

- 容器：独立运行的一个或一组应用。容器是用镜像创建的运行实例。可以被启动、开启、运行、停止等

  可以把容器看做是一个简易版的Linux环境。**每个容器都是相互独立和隔离的**。

- 仓库：集中存放镜像文件的场所。

### docker命令

- 镜像命令

  1. docker images：列出**本地主机**上的镜像

  2. docker search + images名字：在**docker hub**上查询特定image:比如，docker search tomcat

     docker search -s + 数值 + images名字  列出点赞数不小于某个值的所有images

  3. docker pull + images名字：从仓库（如docker hub，阿里云等）上下载images到本地

     注意：docker pull + images名字 = docker pull + images名字：**latest**

  4. docker rmi  (-f)+ images名字或镜像ID均可：删除本地的特定镜像

     同样，如果没有标明要删除的镜像tag，默认删除的是latest标签

     也可以组合命令，如： docker rmi -f ($docker images -qa)

- 容器命令

  1. **新建并启动容器**：docker run [OPTIONS] IMAGES [COMMAND]

     **-i -t经常一起使用**：即以交互式的终端与docker image交互

     --name：为容器指定一个名字

     -d：后台运行容器，非交互式

  2. docker ps ：列出**正在运行**着的容器

     -a：列出当前所有正在运行的容器+**历史上运行过的**

  3. 关闭容器并退出：**exit**，不关闭容器退出：ctrl + P + Q

  4. **启动容器**：docker start + 容器containerID或容器名

  5. 重启容器：docker restart +容器containerID或容器名

  6. 停止容器：docker stop +容器containerID或容器名

  7. 强制停止容器：docker kill +容器containerID容器名

  8. 删除容器：docker rm +容器containerID或容器名；

     一次性删除多个容器：docker rm -f $(docker ps -a -q)

  9. 进入正在运行的容器： **docker attach +容器containerID或容器名**

  10. 从docker容器内拷贝文件到主机上：docker cp 容器ID：容器内路径 目的主机路径
