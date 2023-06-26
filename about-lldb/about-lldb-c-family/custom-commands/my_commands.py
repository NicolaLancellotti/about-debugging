import lldb

def __lldb_init_module(debugger: lldb.SBDebugger, internal_dict: dict):
    container = "my-commands"
    container_help = "A container for my commands"
    debugger.HandleCommand(f'command container add --help "{container_help}" {container}')
    
    command = "my-command"
    command_help = "My command"
    command_func = "my_commands.my_command"
    debugger.HandleCommand(f'command script add --function {command_func} --help "{command_help}" {container} {command}')

def my_command(debugger: lldb.SBDebugger, command: str,
               exe_ctx: lldb.SBExecutionContext,
               result: lldb.SBCommandReturnObject,
               internal_dict: dict):
    result.AppendMessage("my command")
