# All about KlueLogic ErgoDox

## Clone
```bash
cd sandbox
git clone https://github.com/kluelogic/controller.git

cd controller
git clone https://github.com/kluelogic/kll.git
```

## Setting the upstream for a fork (do this once)
```bash
cd controller
git remote -v
git remote add upstream https://github.com/kiibohd/controller.git

cd kll
git remote -v
git remote add upstream https://github.com/kiibohd/kll.git
```

## Syncing a fork
```bash
cd controller
git remote -v # to make sure upstreams are set like this:

# origin	https://github.com/kluelogic/controller.git (fetch)
# origin	https://github.com/kluelogic/controller.git (push)
# upstream	https://github.com/kiibohd/controller.git (fetch)
# upstream	https://github.com/kiibohd/controller.git (push)

git fetch upstream
git checkout master
git merge upstream/master

cd kll
git fetch upstream
git checkout master
git merge upstream/master
```

## Build keyboard with Docker
```bash
# build docker (do this once)
cd controller/Dockerfiles
sudo docker build -f Dockerfile.ubuntu -t controller.ubuntu .

# build keyboard
cd controller
sudo docker run -it --rm -v "$(pwd):/controller" controller.ubuntu
pipenv run pip install pip==18.0 # 18.1 won't work
pipenv install
pipenv shell
./ergodox.bash
```

![build](uml/build.png)

## Keyboard Layout Language

[KLL Spec](https://github.com/kiibohd/kll-spec)

## Keyboard Layout

### ErgoDox Switch ID
![switch_id](images/switch_id.png)

### Scan Code
![scan_code](images/scan_code.png)

### Pixel Mapping (`Scan/Infinity_Ergodox/scancode_map.kll`)
![pixel_map](images/pixel_map.png)

### Key Positioning (`Scan/Infinity_Ergodox/leftHand.kll` and `rightHand.kll`)
![key_pos](images/key_pos.png)

### USB Code (`Scan/Infinity_Ergodox/leftHand.kll` and `rightHand.kll`)
![usb_code](images/usb_code.png)

### Layer 0 (`kll/kll/layouts/infinity_ergodox/my_layer0.kll`)
Deviation from the original ErgoDox layout is shown in _**bold italic**_.

![layer0](images/layer0.png)

### Layer 1 (`kll/kll/layouts/infinity_ergodox/my_layer1.kll`)
This layer pulls in the overflowed keys of layer 0. Deviation from the original ErgoDox layout is shown in _**bold italic**_.

NOTE: **List all keys in relation to the original ErgoDox layout**, not in relation to my layer 0.

![layer1](images/layer1.png)

### Layer 2 (`kll/kll/layouts/infinity_ergodox/my_layer2.kll`)
This layer is for register programming. A key press increments the value of corresponding register.

![layer2](images/layer2.png)

## Firmware
### Main function (`main.c`)
![main](uml/main.png)
![main_periodic](uml/main_periodic.png)

### Scan loop (`Scan/Infinity_Ergodox/scan_loop.c`)
![Scan_setup](uml/Scan_setup.png)
![Scan_poll](uml/Scan_poll.png)

### LED scan (`Scan/Devices/ISSILed/led_scan.c`)
![LED_setup](uml/LED_setup.png)
![LED_scan](uml/LED_scan.png)


## Tools

### Doxygen
```bash
cd doc
make html # then open html/index.html
```

### UML
```bash
cd doc # edit uml/*.uml if necessary
make uml
```

### Markdown previewer
#### [Dillinger](https://dillinger.io/) - won't show images
#### [grip](https://github.com/joeyespo/grip)
```bash
sudo apt install grip
grip KLUELOGIC_ERGODOX.md # then open http://localhost:6419
```

### File diff and merge - `meld`