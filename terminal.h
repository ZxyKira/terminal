/*-----------------------------------------------------------------------------------------
 *    File Name   :terminal.h
 *    Version     :V1.0.0
 *    Create Date :2020-10-15
 *    Modufy Date :2020-10-15
 *    Information :
 */
#ifndef TERMINAL_H_
#define TERMINAL_H_
#include <stdint.h>
#include <stdbool.h>

#include "terminal_entity.h"

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus
/*-----------------------------------------------------------------------------------------
 *    Parameter
 */

/*-----------------------------------------------------------------------------------------
 *    Extern Function/Variable
 */

/*-----------------------------------------------------------------------------------------
 *    Type/Structure
 */

typedef struct _terminal_abstract_t{
	terminal_xfer_api_t Xfer;
	terminal_command_t* (*getCommands)(void);
	uint32_t (*getCommandsSize)(void);
	const char* (*getPrefix)(void);
	struct{
		void (*onUnknownCommand)(terminal_xfer_api_t *pApi, int argc, char *argv[]);
		void (*onOutOfBuffer)(terminal_xfer_api_t *pApi);
	}Event;
}terminal_abstract_t;

typedef struct _terminal_handle_t{
	char* argv[8];
	char* readBuffer;
	uint32_t readBufferSize;
	uint32_t bufferPointer;
	terminal_abstract_t Abstract;
	uint32_t status;
}terminal_handle_t;

typedef struct _terminal_api_t{
	bool (*init)(terminal_handle_t* pHandle, const terminal_abstract_t *abstract);
	bool (*setBuffer)(terminal_handle_t* pHandle, void* buffer, uint32_t bufferSize);
	bool (*addCommand)(terminal_handle_t* pHandle, const terminal_command_t command);
	bool (*removeCommand)(terminal_handle_t* pHandle, const terminal_command_t command);
	bool (*start)(terminal_handle_t* pHandle);
	bool (*stop)(terminal_handle_t* pHandle);
}terminal_api_t;

/*-----------------------------------------------------------------------------------------
 *    Variable
 */
 
extern const terminal_api_t terminal_api;
/*-----------------------------------------------------------------------------------------
 *    Function
 */
 
#ifdef __cplusplus
}
#endif //__cplusplus
#endif //TERMINAL_H_
/*-----------------------------------------------------------------------------------------
 *    End of file
 */
