#include <stdio.h>
#include <stdint.h>
#include <conio.h>

uint8_t ipByte0 = 0, ipByte1 = 0, ipByte2 = 0, ipByte3 = 0, ipMask = 0;

uint32_t hostIPaddress = 0, netIPmask = 0, netIPaddress = 0, firstIPaddress = 0, lastIPaddress = 0, broadcastIPaddress = 0;

int main(void)
{
    printf("Please enter your IP address (XXX.XXX.XXX.XXX/XX): ");
    scanf("%hhu.%hhu.%hhu.%hhu/%hhu", &ipByte3, &ipByte2, &ipByte1, &ipByte0, &ipMask);
    
    hostIPaddress = ipByte0 + (ipByte1 << 8) + (ipByte2 << 16) + (ipByte3 << 24); 
    
    for (int i = 31; i >= 32 - ipMask; i--)
    {
        netIPmask += 1 << i;
    }

    netIPaddress = hostIPaddress & netIPmask;
    broadcastIPaddress = netIPaddress | ~netIPmask;
    firstIPaddress = netIPaddress + 1;
    lastIPaddress = broadcastIPaddress - 1;


    printf("IP address : %21hhu.%hhu.%hhu.%hhu/%hhu \n", ipByte3, ipByte2, ipByte1, ipByte0, ipMask);
    printf("net IP mask : %20hhu.%hhu.%hhu.%hhu \n", netIPmask >> 24, netIPmask >> 16, netIPmask >> 8, netIPmask);
    printf("Net IP address : %17hhu.%hhu.%hhu.%hhu \n", netIPaddress >> 24, netIPaddress >> 16, netIPaddress >> 8, netIPaddress );
    printf("Broadcast IP address : %11hhu.%hhu.%hhu.%hhu \n", broadcastIPaddress >> 24, broadcastIPaddress >> 16, broadcastIPaddress >> 8, broadcastIPaddress);
    printf("---------------OU--------------\n");
    printf("first IP address : %15hhu.%hhu.%hhu.%hhu \n", firstIPaddress >> 24, firstIPaddress >> 16, firstIPaddress >> 8, firstIPaddress);
    printf("last IP address : %16hhu.%hhu.%hhu.%hhu\n", lastIPaddress >> 24, lastIPaddress >> 16, lastIPaddress >> 8, lastIPaddress);
    printf("Number of machines : %13d machines\n", broadcastIPaddress - firstIPaddress);

    getch();
}
