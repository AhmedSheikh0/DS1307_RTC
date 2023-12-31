/*********************************************************************/
/*********************************************************************/
/******** Author:    Amgad Samir   ***********************************/
/******** Component: TWI           ***********************************/
/******** Layer:     MCAL          ***********************************/
/******** Version:   1.0           ***********************************/
/*********************************************************************/
/*********************************************************************/

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define START_ACK                0x08 /* start has been sent */
#define REP_START_ACK            0x10 /* repeated start */
#define SLAVE_ADD_AND_WR_ACK     0x18 /* Master transmit ( slave address + Write request ) ACK */
#define SLAVE_ADD_AND_RD_ACK     0x40 /* Master transmit ( slave address + Read request ) ACK */
#define MSTR_WR_BYTE_ACK         0x28 /* Master transmit data ACK */
#define MSTR_RD_BYTE_WITH_ACK    0x50 /* Master received data with ACK */
#define MSTR_RD_BYTE_WITH_NACK   0x58 /* Master received data with not ACK */
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 /* means that slave address is received with read request */
#define SLAVE_ADD_RCVD_WR_REQ    0x60 /* means that slave address is received with write request */
#define SLAVE_DATA_RECEIVED      0x80 /* means that a byte is received */
#define SLAVE_BYTE_TRANSMITTED   0xB8 /* means that the written byte is transmitted */


// Prescaler
#define I2C_PRESCALER_1			1
#define I2C_PRESCALER_4			2
#define I2C_PRESCALER_16		3
#define I2C_PRESCALER_64		4

#define ACK_ENABLE		1
#define ACK_DISABLE		2


// NTI

/*TWI_Master Trasmit  Check */
#define I2C_MTXCheckStart         				0x08
#define I2C_MTXCheckReStart       				0x10
#define I2C_MTXCheckSLA_W_WithAck       		0x18
#define I2C_MTXCheckSLA_W_WithOutAck    	   	0x20
#define I2C_MTXCheckData_WithAck       			0x28
#define I2C_MTXCheckData_WithOutAck       		0x30
#define I2C_MTXCheckLostArbitration   			0x38

#define I2C_MRXCheckSLA_R_WithAck           	0x40
#define I2C_MRXCheckSLA_R_WithOutAck           	0x48

#define I2C_MRXCheckData_WithAck             	0x50
#define I2C_MRXCheckData_WithOutAck           	0x58


#endif /* TWI_PRIVATE_H_ */
