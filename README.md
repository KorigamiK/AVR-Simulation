# AVR Simulation

## Introduction

This is a simple starting point to write AVR code on
[avr-gcc](https://gcc.gnu.org/wiki/avr-gcc) and simulate it using
[Simulide](https://www.simulide.com/p/home.html). This simple example is based
on the [Blinking LED](http://seta43.duckdns.org/simulc.html) example for the
Atmega328P. The reason for this is to create a simple, modern, minimal IDE like
exprience on Linux (neovim) without any fancy closed source software like Atmel
Studio.

## Structure

- `src/` contains the source code for the simulation.
- `CmakePresets.json` contains the cmake presets for the `gcc-avr` toolchain.
- `build/AVR` contains the build files for the simulation.

## Demo

Here's a video of the simulation in action.

<video src='https://github.com/KorigamiK/AVR-Simulation/assets/72932688/408e631a-f917-4d1a-933b-8c289843fe24' width=180/>

## Requirements

### Arch Linux

The quick and dirty way

```bash
sudo pacman -S cmake avr-gcc avrdude avr-libc libusb

yay -S simulide
```

### Other distros

Install [Simulide](https://www.simulide.com/p/home.html) (I suggest building
from source) and [avr-gcc](https://gcc.gnu.org/wiki/avr-gcc) using your package
manager.

### Windows

I mean, you can use Windows, but why would you?

- **avr-gcc**

  Download and install [avr-gcc](https://gcc.gnu.org/wiki/avr-gcc) from
  [here](https://sourceforge.net/projects/winavr/files/).

- **Simulide**

  Download and install [Simulide](https://www.simulide.com/p/home.html) from
  [here](https://sourceforge.net/projects/simulide/files/).

## Usage

Run the following to configure the cmake presets for the AVR toolchain.

```bash
cmake --preset AVR
```

The custom cmake compiler for Simulide is `cmake_avrgcc.xml` you can
symlink/copy it to the default custom compiler location at
`/usr/share/simulide/data/codeeditor/compilers/compilers`.

```bash
sudo ln -s cmake_avrgcc.xml /usr/share/simulide/data/codeeditor/compilers/compilers
```

Now, drag and drop the simulation file `blink.sim1` to the Simulide editor.

That's it, now you can just drag and drop the source file from `src/` to the
Simulide editor and compile it using the `cmake_avrgcc` compiler and upload the
hex file to the simulation.

You can run the following to flash the hex file to an actual AVR device through
the USB port.

```bash
cmake --build --preset flash-blink
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file
for details.
