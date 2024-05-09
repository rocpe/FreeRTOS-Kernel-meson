# alloc and port variables are supposed to be set in higher meson.build file or other
alloc = get_option('alloc')
port = get_option('port')

FreeRTOS_inc = include_directories('include/', 'portable/'+port)
FreeRTOS_src = files(
    'glueme.c',
    'croutine.c',
    'event_groups.c',
    'list.c',
    'queue.c',
    'stream_buffer.c',
    'tasks.c',
    'timers.c',
    'portable/'+port+'/port.c'
    )
    
# use whatever lib which will work. Remeber to change glueme.c !
deps = [libopencm3_dep]

FreeRTOS_src += files('portable/MemMang/'+alloc+'.c')

freertos_dep = declare_dependency(dependencies: deps, include_directories: FreeRTOS_inc, sources: FreeRTOS_src)
