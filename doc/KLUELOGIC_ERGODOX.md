# All about KlueLogic ErgoDox

## Keyboard Layout

### Layer 0 (`kll/layouts/my_config.kll`)
Deviation from the original ErgoDox layout is shown in _**bold italic**_.

![layer0](images/layer0.png)

### Layer 1 (`kll/layouts/my_layer1.kll`)
This layer pulls in the overflowed keys of layer 0. Deviation from the original ErgoDox layout is shown in _**bold italic**_.

NOTE: **List all keys in relation to the original ErgoDox layout**, not in relation to my layer 0.

![layer1](images/layer1.png)

### Layer 2 (`kll/layouts/my_layer2.kll`)
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
grip README_FIRST.md # then open http://localhost:6419
```

### File diff and merge - `meld`