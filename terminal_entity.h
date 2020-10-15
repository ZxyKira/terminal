/*-----------------------------------------------------------------------------------------
 *    File Name   :terminal_entity.h
 *    Version     :V1.0.0
 *    Create Date :2020-10-15
 *    Modufy Date :2020-10-15
 *    Information :
 */
#ifndef TERMINAL_ENTITY_H_
#define TERMINAL_ENTITY_H_
#include <stdint.h>
#include <stdbool.h>

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

typedef struct terminal_xfer_api_t{
	char (*getCh)(void);
	void (*putCh)(char ch);
	void (*read)(void* buffer, int len);
	void (*send)(const void* data, int len);
	void (*sendString)(const char* string);
}terminal_xfer_api_t;

typedef struct _terminal_command_t{
	const char* command;
	void* userData;
	bool (*handle)(terminal_xfer_api_t *pApi, void* userData, int argc, char **argv);
}terminal_command_t;

/*-----------------------------------------------------------------------------------------
 *    Variable
 */
 
/*-----------------------------------------------------------------------------------------
 *    Function
 */
 
#ifdef __cplusplus
}
#endif //__cplusplus
#endif //TERMINAL_ENTITY_H_
/*-----------------------------------------------------------------------------------------
 *    End of file
 */
