## About this fork
This fork of the FreeRTOS kernel is aimed at supporting the meson build system with libopencm3. To customize edit the `meson.build` and `glueme.c` files. I assume you know what FreeRTOS is and how it works.

## Getting started
Use this repo as git submodule in your project. I assume that you use libopencm3. If not you have to tweak `glueme.c` and `meson.build` files. 

### Setup
You have a your project with `meson.build`. It has to have:
```meson
...
option('alloc',
    type : 'string',
    value : 'heap_4', #or heap_3 or whatever
    description : 'Allocater file name')
option('port',
    type : 'string',
    value : 'GCC/ARM_CM3', # it needs to match you MC 
    description : 'Port floder')
...
# libopencm3 setup. You could have it installed globally or just for your project.
libopencm3_dep = ...
...
subdir('<path-to-this-repo>') # it will create freertos_dep
...
exe = executable(
    ...
   dependencies: [..., freertos_dep] 
)
...
```
You also need `FreeRTOSConfig.h` file in your project. You can find those in examples across the internet.

If you are unsure still how to do all of this go to XXX example.

## Problems
1. It won't work with stm32h7 because libopencm3 right now doesn't support it fully and FreeRTOS has a bit different directory structure for this type of MCs. TODO: Implement for those MCs.
2. How to write `glueme.c` file for other libraries?
3. Tested only on stm32f103rb so far. Feel free to test it on other MCs and send feedback.

## Repository structure
- The root of this repository contains the three files that are common to 
every port - list.c, queue.c and tasks.c.  The kernel is contained within these 
three files.  croutine.c implements the optional co-routine functionality - which
is normally only used on very memory limited systems.

- The ```./portable``` directory contains the files that are specific to a particular microcontroller and/or compiler. 
See the readme file in the ```./portable``` directory for more information.

- The ```./include``` directory contains the real time kernel header files.
