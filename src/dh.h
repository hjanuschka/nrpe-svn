#ifndef HEADER_DH_H
#include <openssl/dh.h>
#endif
DH *get_dh512()
	{
	static unsigned char dh512_p[]={
		0xAC,0x60,0x86,0x85,0xDD,0x35,0x52,0xDD,0x53,0x07,0x6E,0x5A,
		0xB1,0x75,0x46,0x6E,0x26,0xBB,0x86,0xC9,0x59,0x97,0x1D,0x8B,
		0x41,0xC4,0x75,0xFB,0xED,0x17,0x3D,0xC3,0x76,0xBE,0x50,0x82,
		0x54,0xE9,0xDE,0x73,0x9C,0x7D,0x19,0xA4,0x52,0x2C,0x8A,0xEE,
		0x92,0x2C,0x98,0xF7,0x78,0xC6,0xE8,0xD1,0x00,0xBD,0x13,0x7F,
		0x79,0x6D,0xAD,0xF3,
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
