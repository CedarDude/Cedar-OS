# Cedar-OS
A Lite, Free, Open Source Operating System, Made From Scratch.

> [!NOTE]
> This OS is in pre-release, it will improve over time.

> [!WARNING]
> This OS may be unstable in in real computers, try to run in qemu as we still did not try to run on real pc...
>
> > [!WARNING]
> Now you have to use boot.img and not cedar.img
# How to compile?

This is writen in x86 assembly and C and needs to be created specifically with **NASM**, by running:
`build.sh`

# How to run?

Usually you use **QEMU** to run it on a virtual machine, if you know scripting you could make a script to turn it to an IMG or ISO and load it in VirtualBox, VMware or even real hardware, but that's not recommended.
You use the command `qemu-system-i386 -fda build/boot.img -d int -D fresh_test.txt -M smm=off -no-reboot -no-shutdown
simrun` or `qemu-system-i386 -fda build/boot.img`
