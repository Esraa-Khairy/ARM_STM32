

typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CPCPR;
	u32 RXCPCR;
	u32 TXCPCR;
	u32 T2SCFGR;
	u32 I2SSPR;



}SPI_REG;



#define SPI1	((volatile SPI_REG*)0x40013000)
