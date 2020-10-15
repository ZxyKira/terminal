/*-----------------------------------------------------------------------------------------
 *    File Name   :command_info.c
 *    Version     :V1.0.0
 *    Create Date :2020-10-15
 *    Modufy Date :2020-10-15
 *    Information :
 */
#include "terminal.h"
#include "stdio.h"

/*-----------------------------------------------------------------------------------------
 *    Parameter
 */

/*-----------------------------------------------------------------------------------------
 *    Extern Function/Variable
 */

extern terminal_handle_t te_terminal_handle;

/*-----------------------------------------------------------------------------------------
 *    Local Type/Structure
 */

/*-----------------------------------------------------------------------------------------
 *    Local Variable
 */
const char command_info_text_cmd[] = "version";
char spf[128];
/*-----------------------------------------------------------------------------------------
 *    Variable
 */

/*-----------------------------------------------------------------------------------------
 *    Inline Function
 */
 
/*-----------------------------------------------------------------------------------------
 *    Local Function
 */
static bool command_info_handle(terminal_xfer_api_t *pApi, void* userData, int argc, char **argv){
	pApi->sendString("This a sample command\n");
	int i;
	
	for(i=0; i<argc; i++){
		int len = sprintf(&spf[0], "argv[%d] = %s\n", i, argv[i]);
		pApi->send(&spf[0], len);
	}

	return true;
}

/*-----------------------------------------------------------------------------------------
 *    Public Function
 */
void command_info_init(){
	const terminal_command_t command = {
		.command = command_info_text_cmd,
		.userData = (void*)0x00000000,
		.handle = command_info_handle,
	};	
	
	terminal_api.addCommand(&te_terminal_handle, command);
}


/*-----------------------------------------------------------------------------------------
 *    End of file
 */

