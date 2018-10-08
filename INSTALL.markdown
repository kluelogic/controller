## Install Docker

https://docs.docker.com/install/linux/docker-ce/ubuntu/

## Create a local clone of controller

```bash
git clone https://github.com/kluelogic/controller.git

# Cloning into 'controller'...
# remote: Counting objects: 4157, done.        
# remote: Compressing objects: 100% (2/2), done.        
# remote: Total 4157 (delta 0), reused 0 (delta 0), pack-reused 4155        
# Receiving objects: 100% (4157/4157), 1.40 MiB | 0 bytes/s, done.
# Resolving deltas: 100% (2668/2668), done.
# Checking connectivity... done.
```

## Configure Git to sync my fork with the original controller repository

```bash
cd controller/
git remote -v

# origin	https://github.com/kluelogic/controller.git (fetch)
# origin	https://github.com/kluelogic/controller.git (push)

git remote add upstream https://github.com/kiibohd/controller.git
git remote -v

# origin	https://github.com/kluelogic/controller.git (fetch)
# origin	https://github.com/kluelogic/controller.git (push)
# upstream	https://github.com/kiibohd/controller.git (fetch)
# upstream	https://github.com/kiibohd/controller.git (push)

git pull https://github.com/kiibohd/controller.git master

# Already up-to-date.

git push
```

## Create a local clone of kll

```bash
cd controller/
git clone https://github.com/kluelogic/kll.git
cd kll/
git remote add upstream https://github.com/kiibohd/kll.git
git remote -v
git pull https://github.com/kiibohd/kll.git master
git push
```
