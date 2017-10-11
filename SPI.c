/*
 * SPI.c
 *
 *  Created on: Sep 27, 2017
 *      Author: Andres Hernandez
 */

#include "SPI.h"

/*it enable the clock module of the SPI by modifying the MDIS bits*/
static void SPI_enable(SPI_ChannelType channel){//COMPLETE
	switch(channel){
	case SPI_0:
		SPI0->MCR &= ~(SPI_MCR_MDIS_MASK);
		break;
	case SPI_1:
		SPI1->MCR &= ~(SPI_MCR_MDIS_MASK);
		break;
	case SPI_2:
		SPI2->MCR &= ~(SPI_MCR_MDIS_MASK);
		break;
	default:
		break;
	}
}
/*It activate the clock gating*/
static void SPI_clk(SPI_ChannelType channel){//COMPLETE
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
static void SPI_setMaster(SPI_ChannelType channel, SPI_MasterType masterOrSlave){//COMPLETE
	switch(channel){
	case SPI_0:
<<<<<<< HEAD
		if(0 == masterOrSlave){SPI0->MCR &= ~(SPI_MCR_MSTR_MASK);}
		else{SPI0->MCR |= (SPI_MCR_MSTR_MASK);}
		break;
	case SPI_1:
		if(0 == masterOrSlave){SPI1->MCR &= ~(SPI_MCR_MSTR_MASK);}
		else{SPI1->MCR |= (SPI_MCR_MSTR_MASK);}
		break;
	case SPI_2:
		if(0 == masterOrSlave){SPI2->MCR &= ~(SPI_MCR_MSTR_MASK);}
		else{SPI2->MCR |= (SPI_MCR_MSTR_MASK);}
=======
		SPI0->MCR |= (masterOrSlave<<BIT31);
		break;
	case SPI_1:
		SPI1->MCR = (masterOrSlave<<BIT31) & (1<<BIT31);
		break;
	case SPI_2:
		SPI2->MCR = (masterOrSlave<<BIT31) & (1<<BIT31);
>>>>>>> d6f9500020c60109614262d9e926ba418d742010
		break;
	default:
		break;
	}
}
/*It activate the TX and RX FIFOs of the SPI depending on the value of enableOrdisable*/
static void SPI_fIFO(SPI_ChannelType channel, SPI_EnableFIFOType enableOrDisable){//COMPLETE
	switch(channel){
	case SPI_0:
<<<<<<< HEAD
		if(0 == enableOrDisable){
			SPI0->MCR |= (SPI_MCR_DIS_RXF_MASK);
			SPI0->MCR |= (SPI_MCR_DIS_TXF_MASK);
		}else{
			SPI0->MCR &= ~(SPI_MCR_DIS_RXF_MASK);
			SPI0->MCR &= ~(SPI_MCR_DIS_TXF_MASK);
		}
		break;
	case SPI_1:
		if(0 == enableOrDisable){
			SPI1->MCR |= SPI_MCR_DIS_RXF_MASK;
			SPI1->MCR |= SPI_MCR_DIS_TXF_MASK;
		}else{
			SPI1->MCR &= ~(SPI_MCR_DIS_RXF_MASK);
			SPI1->MCR &= ~(SPI_MCR_DIS_TXF_MASK);
		}
		break;
	case SPI_2:
		if(0 == enableOrDisable){
			SPI2->MCR |= SPI_MCR_DIS_RXF_MASK;
			SPI2->MCR |= SPI_MCR_DIS_TXF_MASK;
		}else{
			SPI2->MCR &= ~(SPI_MCR_DIS_RXF_MASK);
			SPI2->MCR &= ~(SPI_MCR_DIS_TXF_MASK);
		}
=======
		SPI0->MCR = (enableOrDisable<<BIT13) & (1<<BIT13);
		SPI0->MCR = (enableOrDisable<<BIT12) & (1<<BIT12);
		break;
	case SPI_1:
		SPI1->MCR = (enableOrDisable<<BIT13) & (1<<BIT13);
		SPI1->MCR = (enableOrDisable<<BIT12) & (1<<BIT12);
		break;
	case SPI_2:
		SPI2->MCR = (enableOrDisable<<BIT13) | (1<<BIT13);
		SPI2->MCR = (enableOrDisable<<BIT12) | (1<<BIT12);
>>>>>>> d6f9500020c60109614262d9e926ba418d742010
		break;
	default:
		break;
	}
}
/*It selects the clock polarity depending on the value of cpol*/
static void SPI_clockPolarity(SPI_ChannelType channel, SPI_PolarityType cpol){//COMPLETE
	switch(channel){
	case SPI_0:
<<<<<<< HEAD
		if(0 == cpol){SPI0->CTAR[0] &= ~(SPI_CTAR_CPOL_MASK);}
		else{SPI0->CTAR[0] |= SPI_CTAR_CPOL_MASK;}
		break;
	case SPI_1:
		if(0 == cpol){SPI0->CTAR[1] &= ~(SPI_CTAR_CPOL_MASK);}
		else{SPI0->CTAR[1] |= SPI_CTAR_CPOL_MASK;}
		break;
	case SPI_2:
		if(0 == cpol){SPI0->CTAR[2] &= ~(SPI_CTAR_CPOL_MASK);}
		else{SPI0->CTAR[2] |= SPI_CTAR_CPOL_MASK;}
=======
		SPI0->CTAR[0] |= (cpol<<BIT26);
		break;
	case SPI_1:
		SPI1->CTAR[1] |= (cpol<<BIT26);
		break;
	case SPI_2:
		SPI2->CTAR[2] |= (cpol<<BIT26);
>>>>>>> d6f9500020c60109614262d9e926ba418d742010
		break;
	default:
		break;
	}
}
/*It selects the frame size depending on the value of frameSize and the macros that are defined above*/
static void SPI_frameSize(SPI_ChannelType channel, uint32 frameSize){
	//frameSize = frameSize;
	switch(channel){
	case SPI_0:
<<<<<<< HEAD
		SPI0->CTAR[0] &= ~(SPI_CTAR_FMSZ_MASK);
		SPI0->CTAR[0] |= frameSize;
		break;
	case SPI_1:
		SPI1->CTAR[1] &= ~(SPI_CTAR_FMSZ_MASK);
		SPI1->CTAR[1] |= frameSize;
		break;
	case SPI_2:
		SPI2->CTAR[2] &= ~(SPI_CTAR_FMSZ_MASK);
=======
		SPI0->CTAR[0] |= (frameSize);
		break;
	case SPI_1:
		SPI1->CTAR[1] |= frameSize;
		break;
	case SPI_2:
>>>>>>> d6f9500020c60109614262d9e926ba418d742010
		SPI2->CTAR[2] |= frameSize;
		break;
	default:
		break;
	}
}
/*It selects the clock phase depending on the value of cpha*/
static void SPI_clockPhase(SPI_ChannelType channel, SPI_PhaseType cpha){//COMPLETE
	switch(channel){
	case SPI_0:
<<<<<<< HEAD
		if(0 == cpha){SPI0->CTAR[0] &= ~(SPI_CTAR_CPHA_MASK);}
		else{SPI0->CTAR[0] |= (SPI_CTAR_CPHA_MASK);}
		break;
	case SPI_1:
		if(0 == cpha){SPI1->CTAR[1] &= ~(SPI_CTAR_CPHA_MASK);}
		else{SPI1->CTAR[1] |= (SPI_CTAR_CPHA_MASK);}
		break;
	case SPI_2:
		if(0 == cpha){SPI2->CTAR[2] &= ~(SPI_CTAR_CPHA_MASK);}
		else{SPI2->CTAR[2] |= (SPI_CTAR_CPHA_MASK);}
=======
		SPI0->CTAR[0] |= (cpha<<BIT25);
		break;
	case SPI_1:
		SPI1->CTAR[1] |= (cpha<<BIT25);
		break;
	case SPI_2:
		SPI2->CTAR[2] |= (cpha<<BIT25);
>>>>>>> d6f9500020c60109614262d9e926ba418d742010
		break;
	default:
		break;
	}
}
/*It selects the baud rate depending on the value of baudRate and the macros that are defined above*/
static void SPI_baudRate(SPI_ChannelType channel, uint32 baudRate){//COMPLETE

	switch(channel){
	case SPI_0:
<<<<<<< HEAD
		SPI0->CTAR[0] &= ~(SPI_CTAR_BR_MASK);
		SPI0->CTAR[0] |= baudRate;
		break;
	case SPI_1:
		SPI1->CTAR[1] &= ~(SPI_CTAR_BR_MASK);
		SPI1->CTAR[1] |= baudRate;
		break;
	case SPI_2:
		SPI2->CTAR[2] &= ~(SPI_CTAR_BR_MASK);
=======
		SPI0->CTAR[0] |= baudRate ;
		break;
	case SPI_1:
		SPI1->CTAR[1] |= baudRate;
		break;
	case SPI_2:
>>>>>>> d6f9500020c60109614262d9e926ba418d742010
		SPI2->CTAR[2] |= baudRate;
		break;
	default:
		break;
	}
}
/*It selects if MSB or LSM bits is first transmitted*/
static void SPI_mSBFirst(SPI_ChannelType channel, SPI_LSMorMSBType msb){//COMPLETE
	switch(channel){
	case SPI_0:
<<<<<<< HEAD
		if(0 == msb){SPI0->CTAR[0] &= ~(SPI_CTAR_LSBFE_MASK);}
		else{SPI0->CTAR[0] |= SPI_CTAR_LSBFE_MASK;}
		break;
	case SPI_1:
		if(0 == msb){SPI1->CTAR[1] &= ~(SPI_CTAR_LSBFE_MASK);}
		else{SPI1->CTAR[1] |= SPI_CTAR_LSBFE_MASK;}
		break;
	case SPI_2:
		if(0 == msb){SPI2->CTAR[2] &= ~(SPI_CTAR_LSBFE_MASK);}
		else{SPI2->CTAR[2] |= SPI_CTAR_LSBFE_MASK;}
=======
		SPI0->CTAR[0] |= (msb<<BIT24);
		break;
	case SPI_1:
		SPI1->CTAR[1] |= (msb<<BIT24);
		break;
	case SPI_2:
		SPI2->CTAR[2] |= (msb<<BIT24);
>>>>>>> d6f9500020c60109614262d9e926ba418d742010
		break;
	default:
		break;
	}
}
/*It stars the SPI transmission by modifying the value of HALT bit*/
void SPI_startTranference(SPI_ChannelType channel){//COMPLETE
	switch(channel){
	case SPI_0:
<<<<<<< HEAD
		SPI0->MCR &= ~(SPI_MCR_HALT_MASK);
=======
		SPI0->MCR &= (1<<BIT31);
>>>>>>> d6f9500020c60109614262d9e926ba418d742010
		break;
	case SPI_1:
		SPI1->MCR &= ~(SPI_MCR_HALT_MASK);
		break;
	case SPI_2:
		SPI2->MCR &= ~(SPI_MCR_HALT_MASK);
		break;
	default:
		break;
	}
}
/*It stops the SPI transmission by modifying the value of HALT bit*/
void SPI_stopTranference(SPI_ChannelType channel){//COMPLETE
	switch(channel){
	case SPI_0:
		SPI0->MCR |= SPI_MCR_HALT_MASK;
		break;
	case SPI_1:
		SPI1->MCR |= SPI_MCR_HALT_MASK;
		break;
	case SPI_2:
		SPI2->MCR |= SPI_MCR_HALT_MASK;
		break;
	default:
		break;
	}
}
/*It transmits the information contained in data*/
<<<<<<< HEAD
void SPI_sendOneByte(uint8 Data){//COMPLETE
	SPI0->PUSHR |= (Data);
	while(0 == (SPI0->SR & SPI_SR_TCF_MASK));
	SPI0->SR |= SPI_SR_TCF_MASK;
=======
void SPI_sendOneByte(SPI_ChannelType channel,uint8 Data){
	SPI0->PUSHR |= (Data);
	while(FALSE == (SPI0->SR & SPI_SR_TCF_MASK));
	SPI0->SR |= SPI_SR_TCF_MASK;

	/*switch(channel){
	case SPI_0:
		SPI0->PUSHR = (Data);
		while(FALSE == (SPI0->SR & SPI_SR_TCF_MASK));
		SPI0->SR |= SPI_SR_TCF_MASK;
		break;*
/*	case SPI_1:
		SPI1->PUSHR = (Data);
		while(FALSE == (SPI1->SR & SPI_SR_TCF_MASK));
		SPI1->SR |= SPI_SR_TCF_MASK;
		break;
	case SPI_2:
		SPI2->PUSHR = (Data);
		while(FALSE == (SPI2->SR & SPI_SR_TCF_MASK));
		SPI2->SR |= SPI_SR_TCF_MASK;
		break;
	default:
		break;*/






>>>>>>> d6f9500020c60109614262d9e926ba418d742010
}
/*It configures the SPI for transmission, this function as arguments receives a pointer to a constant structure where are all
 * the configuration parameters*/
void SPI_init(const SPI_ConfigType* SPI_Config){//COMPLETE

	GPIO_clockGating(SPI_Config->GPIOForSPI.GPIO_portName);
	GPIO_pinControlRegister(SPI_Config->GPIOForSPI.GPIO_portName,SPI_Config->GPIOForSPI.SPI_clk,&(SPI_Config->pinConttrolRegisterPORTD));
	GPIO_pinControlRegister(SPI_Config->GPIOForSPI.GPIO_portName,SPI_Config->GPIOForSPI.SPI_Sout,&(SPI_Config->pinConttrolRegisterPORTD));
<<<<<<< HEAD
	SPI_setMaster(SPI_Config->SPI_Channel, SPI_Config->SPI_Master);
	SPI_fIFO(SPI_Config->SPI_Channel, SPI_Config->SPI_EnableFIFO);
	SPI_enable(SPI_Config->SPI_Channel);
=======
	SPI_clk(SPI_Config->SPI_Channel);
	SPI_fIFO(SPI_Config->SPI_Channel, SPI_Config->SPI_EnableFIFO);
	SPI_enable(SPI_Config->SPI_Channel);
	SPI_setMaster(SPI_Config->SPI_Channel, SPI_Config->SPI_Master);
>>>>>>> d6f9500020c60109614262d9e926ba418d742010
	SPI_clockPolarity(SPI_Config->SPI_Channel, SPI_Config->SPI_Polarity);
	SPI_frameSize(SPI_Config->SPI_Channel, SPI_Config->frameSize);
	SPI_clockPhase(SPI_Config->SPI_Channel, SPI_Config->SPI_Phase);
	SPI_baudRate(SPI_Config->SPI_Channel, SPI_Config->baudrate);
	SPI_mSBFirst(SPI_Config->SPI_Channel, SPI_Config->SPI_LSMorMSB);
}
