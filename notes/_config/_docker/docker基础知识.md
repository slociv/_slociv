docker 的目的就是为了快速部署配置转移项目

#### 1.配置一次到处运行
#### 2.减少了开DEV和OPS团队之间额外交流的开销
docker 环境简化了配置，减少了错误
#### 3.虚拟机 vs docker
应用层 内核层 硬件

docker 只虚拟化到了应用层 ，用的还是操作系统的内核
虚拟机 不仅虚拟化了应用层他 连内核层也虚拟化了

这就导致了docker镜像更小只需几mb
这也导致了 docker 更快，更小，
但是docker最初是基于linux 内核开发的，所以docker中只兼容linux发行版，但是vm中可以兼容所有的os

这也引出了问题，docker最初基于linux内核开发，随着docker的发展
docker也兼容了windows内核和macos内核，所以这就允许
允许在在windows和macos上运行docker的linux容器

在windows和macos需要一个Hypervisor Layer来提供linux kernel 运行docker
#### 4.install docker
yay -Sy docker
yay -Sy  gnome-shell-extension-appindicator
yay -Sy docker-desktop
#### 5.docker images vs docker containers
1.docker 允许将环境配置打包到这个包中以便轻松的共享和分发
2.like a zip or tarfile or jar file 可以存储到artifact repository 中，被需要的时候下载到服务器或本地，然后我们使用docker将生成的包或者工件用docker打包这个叫做docker image
    artfact软件工件是软件开发过程中生产的副产品。它可能包括项目源代码，依赖项，
可以说docker image 是一个可以执行的应用工件，不仅包含已经编译的应用程序的代码，而且还包含有关配置信息

一个image可以分发给多个容器运行

manjaro 配置docker镜像
systemctl start docker

sudo vim /etc/docker/daemon.json


{
    "registry-mirrors":"https://registry.docker-cn.com"
}

systemctl daemon-reload

systemctl restart docker

docker version

sudo docker info | grep Storage

