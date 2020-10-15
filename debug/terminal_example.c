/*-----------------------------------------------------------------------------------------
 *    File Name   :terminal_example.c
 *    Version     :V1.0.0
 *    Create Date :2020-10-15
 *    Modufy Date :2020-10-15
 *    Information :
 */
#include <stdio.h>
#include <conio.h>
#include <string.h>

#include "terminal.h"

/*-----------------------------------------------------------------------------------------
 *    Parameter
 */
#define TE_DEFINE_MAX_OF_COMMAND 16
#define TE_DEFINE_INPUT_BUFFER_SIZE 16

/*-----------------------------------------------------------------------------------------
 *    Extern Function/Variable
 */

/*-----------------------------------------------------------------------------------------
 *    Local Type/Structure
 */

/*-----------------------------------------------------------------------------------------
 *    Local Variable
 */
static char te_text_unknownCommand[] = "unknown command.\n";
static char te_text_outOfMemory[] = "Out of memory.\n";

static terminal_command_t te_terminal_command[TE_DEFINE_MAX_OF_COMMAND];
static char te_input_buffer[TE_DEFINE_INPUT_BUFFER_SIZE];

/*-----------------------------------------------------------------------------------------
 *    Variable
 */
 
terminal_handle_t te_terminal_handle;

/*-----------------------------------------------------------------------------------------
 *    Inline Function
 */
 
/*-----------------------------------------------------------------------------------------
 *    Local Function
 */
static char te_abstract_xfer_getCh(void){
	char result = getch();
	switch(result){
		case 0x0D:
			printf("\n");
			return '\n';
		default:
			printf("%c",result);
			return result;
	}
}

static void te_abstract_xfer_putCh(char ch){
	printf("%c");
}

static void te_abstract_xfer_read(void* buffer, int len){
	int i;
	char* pbuf = (char*)buffer;
	for(i=0; i<len; i++){
		pbuf[i] = getch();
	}
}

static void te_abstract_xfer_send(const void* data, int len){
	int i;
	char* ch = (char*)data;
	
	for(i=0; i<len; i++){
		printf("%c", ch[i]);
	}
}

static void te_abstract_xfer_sendString(const char* string){
	te_abstract_xfer_send(string, strlen(string));
}

static terminal_command_t* te_abstract_getCommands(void){
	return &te_terminal_command[0];
}

static uint32_t te_abstract_getCommandsSize(void){
	return TE_DEFINE_MAX_OF_COMMAND;
}

static const char* te_abstract_getPrefix(void){
	return "LPC845\0";
}

static void te_abstract_event_onUnknownCommand(terminal_xfer_api_t *pApi, int argc, char *argv[]){
	pApi->send(te_text_unknownCommand, strlen(te_text_unknownCommand));
}

static void te_abstract_event_onOutOfBuffer(terminal_xfer_api_t *pApi){
	pApi->send(te_text_outOfMemory, strlen(te_text_outOfMemory));
}
/*-----------------------------------------------------------------------------------------
 *    Public Function
 */
void te_init(void){
	const terminal_abstract_t abstract = {
		.Xfer = {
			.getCh = te_abstract_xfer_getCh,
			.putCh = te_abstract_xfer_putCh,
			.read = te_abstract_xfer_read,
			.send = te_abstract_xfer_send,
			.sendString = te_abstract_xfer_sendString
		},
		.getCommands = te_abstract_getCommands,
		.getCommandsSize = te_abstract_getCommandsSize,
		.getPrefix = te_abstract_getPrefix,
		.Event = {
			.onUnknownCommand = te_abstract_event_onUnknownCommand,
			.onOutOfBuffer = te_abstract_event_onOutOfBuffer
		}
	};
	
	terminal_api.init(&te_terminal_handle, &abstract);
	terminal_api.setBuffer(&te_terminal_handle, &te_input_buffer[0], TE_DEFINE_INPUT_BUFFER_SIZE);
}

void te_start(void){
	terminal_api.start(&te_terminal_handle);
}

/*-----------------------------------------------------------------------------------------
 *    End of file
 */

