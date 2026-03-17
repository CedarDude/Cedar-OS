#include "drivers/vga.h"
#include "drivers/keyboard.h"
#include "sysapp/sysapp.h"
#include "idt.h"

void kernel_main() {
    MK_delay(1050);

    // IT VGA_SET_COLOR not MK_VGA_SET_COLOR FUCKER.
    MK_vga_set_color(0x0E);
    MK_vga_print("KERNEL FOUND AND READ==================================\n");
    MK_vga_reset_color();

    MK_delay(2000);
    MK_clear_screen();
    init_keyboard();
    init_idt();
    MK_clear_screen();
    MK_delay(980);
    MK_vga_print(".-----------------------------------------------------------------------------.\n");
    MK_vga_print("|                             Cedar OS MangoKernel                            |\n");
    MK_delay(500);
    MK_vga_print("|                              COPYRIGHT JAD 2026                             |\n");
    MK_vga_print("'-----------------------------------------------------------------------------'\n");
    MK_delay(1000);
    MK_vga_print("============================CEDAROS_FALLBACK_DOS_MODE=========================\n\n");
    MK_delay(170);
    MK_vga_print("All systems are up and running, booting into fallback dos mode...\n");
    MK_delay(200);
    

    MK_vga_print("dev note: back space still not added, if you used backspace on your command, it will fail.\n");

    MK_sysapp_prompt();
    char line[MK_LINE_MAX];
    int idx = 0;
    line[0] = '\0';
    while (1) {
        char c = read_key();
        if (c) {
            if (c == '\b') {
                if (idx > 0) {
                    idx--;
                    line[idx] = '\0';
                    MK_vga_backspace();
                }
            } else if (c == '\n') {
                MK_vga_print_char('\n');
                {
                    int i = 0;
                    while (line[i] == ' ') i++;
                    if (line[i])
                        if (!MK_sysapp_run(line))
                            MK_vga_print("Unknown command\n");
                }
                idx = 0;
                line[0] = '\0';
                MK_sysapp_prompt();
            } else if (idx < MK_LINE_MAX - 1 && (unsigned char)c >= 32) {
                line[idx++] = c;
                line[idx] = '\0';
                MK_vga_print_char(c);
            }
        }
        MK_delay(50);
        // delays for this thing.
    }
}
