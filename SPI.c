/*
 * SPI.c
 *
 *  Created on: Sep 27, 2017
 *      Author: Andres Hernandez
 */

#include "SPI.h"

/*it enable the clock module of the SPI by modifying the MDIS bits*/
static void SPI_enable(SPI_ChannelType channel){
	switch(channel){
	case SPI_0:
		SPI0->MCR |= 0<<BIT14;
		break;
	case SPI_1:
		SPI1->MCR |= 0<<BIT14;
		break;
	case SPI_2:
		SPI2->MCR |= 0<<BIT14;
		break;
	default:
		break;
	}
}
/*It activate the clock gating*/
static void SPI_clk(SPI_ChannelType channel){
	switch(channel){
	case SPI_0:
		SIM->SCGC6 |= SPI0_CLOCK_GATING;
		break;
	case SPI_1:
		SIM->SCGC6 |= SPI1_CLOCK_GATING;
		break;
	case SPI_2:
		SIM->SCGC3 |= SPI2_CLOCK_GATING;
		break;
	default:
		break;
	}
}
/*It configure the SPI as a master or slave depending on the value of masterOrslave*/
static void SPI_setMaster(SPI_ChannelType channel, SPI_MasterType masterOrSlave){
	switch(channel){
	case SPI_0:
		SPI0->MCR = (masterOrSlave<<31) & (1<<BIT31);
		break;
	case SPI_1:
		SPI1->MCR = (masterOrSlave<<31) & (1<<BIT31);
		break;
	case SPI_2:
		SPI2->MCR = (masterOrSlave<<31) & (1<<BIT31);
		break;
	default:
		break;
	}
}
/*It activate the TX and RX FIFOs of the SPI depending on the value of enableOrdisable*/
static void SPI_fIFO(SPI_ChannelType channel, SPI_EnableFIFOType enableOrDisable){
	switch(channel){
	case SPI_0:
		SPI0->MCR = (enableOrDisable<<13) & (1<<BIT13);
		SPI0->MCR = (enableOrDisable<<12) & (1<<BIT12);
		break;
	case SPI_1:
		SPI1->MCR = (enableOrDisable<<13) & (1<<BIT13);
		SPI1->MCR = (enableOrDisable<<12) & (1<<BIT12);
		break;
	case SPI_2:
		SPI2->MCR = (enableOrDisable<<13) | (1<<BIT13);
		SPI2->MCR = (enableOrDisable<<12) | (1<<BIT12);
		break;
	default:
		break;
	}
}
/*It selects the clock polarity depending on the value of cpol*/
static void SPI_clockPolarity(SPI_ChannelType channel, SPI_PolarityType cpol){
	switch(channel){
	case SPI_0:
		SPI0->CTAR[26] |= (cpol<<26);
		break;
	case SPI_1:
		SPI1->CTAR[26] |= (cpol<<26);
		break;
	case SPI_2:
		SPI2->CTAR[26] |= (cpol<<26);
		break;
	default:
		break;
	}
}
/*It selects the frame size depending on the value of frameSize and the macros that are defined above*/
static void SPI_frameSize(SPI_ChannelType channel, uint32 frameSize){
	switch(channel){
	case SPI_0:
		SPI0->CTAR[0] |= frameSize;
		break;
	case SPI_1:
		SPI1->CTAR[1] |= frameSize;
		break;
	case SPI_2:
		SPI2->CTAR[2]|= frameSize;
		break;
	default:
		break;
	}
}
/*It selects the clock phase depending on the value of cpha*/
static void SPI_clockPhase(SPI_ChannelType channel, SPI_PhaseType cpha){
	switch(channel){
	case SPI_0:
		SPI0->CTAR[25] |= (cpha<<25);
		break;
	case SPI_1:
		SPI1->CTAR[25] |= (cpha<<25);
		break;
	case SPI_2:
		SPI2->CTAR[25] |= (cpha<<25);
		break;
	default:
		break;
	}
}
/*It selects the baud rate depending on the value of baudRate and the macros that are defined above*/
static void SPI_baudRate(SPI_ChannelType channel, uint32 baudRate){

	switch(channel){
	case SPI_0:
		SPI0->CTAR[0] |= baudRate ;
		break;
	case SPI_1:
		SPI1->CTAR[1] |= baudRate;
		break;
	case SPI_2:
		SPI2->CTAR[2] |= baudRate;
		break;
	default:
		break;
	}
}
/*It selects if MSB or LSM bits is first transmitted*/
static void SPI_mSBFirst(SPI_ChannelType channel, SPI_LSMorMSBType msb){
	switch(channel){
	case SPI_0:
		SPI0->CTAR[24] |= (msb<<24);
		break;
	case SPI_1:
		SPI1->CTAR[24] |= (msb<<24);
		break;
	case SPI_2:
		SPI2->CTAR[24] |= (msb<<24);
		break;
	default:
		break;
	}
}
/*It stars the SPI transmission by modifying the value of HALT bit*/
void SPI_startTranference(SPI_ChannelType channel){
	switch(channel){
	case SPI_0:
		SPI0->MCR |= (0<<0);
		break;
	case SPI_1:
		SPI1->MCR |= (0<<0);
		break;
	case SPI_2:
		SPI2->MCR |= (0<<0);
		break;
	default:
		break;
	}
}
/*It stops the SPI transmission by modifying the value of HALT bit*/
void SPI_stopTranference(SPI_ChannelType channel){
	switch(channel){
	case SPI_0:
		SPI0->MCR |= (1<<0);
		break;
	case SPI_1:
		SPI1->MCR |= (1<<0);
		break;
	case SPI_2:
		SPI2->MCR |= (1<<0);
		break;
	default:
		break;
	}
}
/*It transmits the information contained in data*/
void SPI_sendOneByte(SPI_ChannelType channel,uint8 Data){
	switch(channel){
	case SPI_0:
		SPI0->PUSHR = (Data);
		while(FALSE == (SPI0->SR & SPI_SR_TCF_MASK));
		SPI0->SR |= SPI_SR_TCF_MASK;
	case SPI_1:
		SPI1->PUSHR = (Data);
		while(FALSE == (SPI1->SR & SPI_SR_TCF_MASK));
		SPI1->SR |= SPI_SR_TCF_MASK;
	case SPI_2:
		SPI2->PUSHR = (Data);
		while(FALSE == (SPI2->SR & SPI_SR_TCF_MASK));
		SPI2->SR |= SPI_SR_TCF_MASK;


	}

}
/*It configures the SPI for transmission, this function as arguments receives a pointer to a constant structure where are all
 * the configuration parameters*/
void SPI_init(const SPI_ConfigType* SPI_Config){

	SPI_clk(SPI_Config->SPI_Channel);
	GPIO_clockGating(SPI_Config->GPIOForSPI.GPIO_portName);
	GPIO_pinControlRegister(SPI_Config->GPIOForSPI.GPIO_portName,SPI_Config->GPIOForSPI.SPI_clk,&(SPI_Config->pinConttrolRegisterPORTD));
	GPIO_pinControlRegister(SPI_Config->GPIOForSPI.GPIO_portName,SPI_Config->GPIOForSPI.SPI_Sout,&(SPI_Config->pinConttrolRegisterPORTD));
	SPI_enable(SPI_Config->SPI_Channel);
	SPI_setMaster(SPI_Config->SPI_Channel, SPI_Config->SPI_Master);
	SPI_fIFO(SPI_Config->SPI_Channel, SPI_Config->SPI_EnableFIFO);
	SPI_clockPolarity(SPI_Config->SPI_Channel, SPI_Config->SPI_Polarity);
	SPI_frameSize(SPI_Config->SPI_Channel, SPI_Config->frameSize);
	SPI_clockPhase(SPI_Config->SPI_Channel, SPI_Config->SPI_Phase);
	SPI_baudRate(SPI_Config->SPI_Channel, SPI_Config->baudrate);
	SPI_mSBFirst(SPI_Config->SPI_Channel, SPI_Config->SPI_LSMorMSB);
}
