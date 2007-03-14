#ifndef HEADER_DH_H
#include <openssl/dh.h>
#endif
DH *get_dh512()
	{
	static unsigned char dh512_p[]={
		0x84,0x4C,0xF3,0x18,0x54,0x6A,0x8A,0xEA,0xC6,0x87,0x69,0xA0,
		0x1C,0x59,0x32,0x2A,0x4B,0xF7,0xD9,0x33,0xCC,0xDC,0xFD,0xF0,
		0x8D,0xC4,0xBD,0x8A,0xA5,0xB3,0xE3,0xBD,0x68,0xFD,0xED,0x78,
		0x24,0x17,0x73,0x3A,0x5D,0x7A,0x1F,0x99,0xF6,0x41,0x5B,0x49,
		0xE3,0xA2,0xD9,0x30,0xB1,0x98,0xCA,0xB4,0xB6,0x5F,0x91,0xCE,
		0x09,0x62,0xFD,0x4B,
		};
	static unsigned char dh512_g[]={
		0x02,
		};
	DH *dh;

	if ((dh=DH_new()) == NULL) return(NULL);
	dh->p=BN_bin2bn(dh512_p,sizeof(dh512_p),NULL);
	dh->g=BN_bin2bn(dh512_g,sizeof(dh512_g),NULL);
	if ((dh->p == NULL) || (dh->g == NULL))
		{ DH_free(dh); return(NULL); }
	return(dh);
	}
