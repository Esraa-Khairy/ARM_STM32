





typedef struct
{
	u32 CCR;
	u32 CNDTR;
	u32 CPAR;
	u32 CMAR;
	u32 Reserved;

}DMA_channel;


typedef struct
{
	u32 ISR;
	u32 IFCR;
	DMA_channel channel [7];


}DMA_type;

#define MYDMA ((volatile DMA_type*)0x40020000)
