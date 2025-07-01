/* as it is my firts time using frtos, below code is based on https://github.com/WRansohoff/min_freertos_blink/blob/master/FreeRTOSConfig.h and related to it tutorial on vivonomicon */

#ifndef FREERTOS_CONFIG_H

#define FREERTOS_CONFIG_H




#define configUSE_PREEMPTION                                        1

#define configUSE_PORT_OPTIMISED_TASK_SELECTION                     1

#define configUSE_TICKLESS_IDLE                                     0

#define configCPU_CLOCK_HZ                                          ( ( unsigned long ) 72000000 )  

#define configSYSTICK_CLOCK_HZ                                      ( configCPU_CLOCK_HZ / 8 )

#define configTICK_RATE_HZ                                          250

#define configMAX_PRIORITIES                                        5

#define configMINIMAL_STACK_SIZE                                    128

#define configMAX_TASK_NAME_LEN                                     16

#define configUSE_16_BIT_TICKS                                      0

#define configIDLE_SHOULD_YIELD                                     1

#define configUSE_TASK_NOTIFICATIONS                                0

#define configTASK_NOTIFICATION_ARRAY_ENTRIES                       3

#define configUSE_MUTEXES                                           0

#define configUSE_RECURSIVE_MUTEXES                                 0

#define configUSE_COUNTING_SEMAPHORES                               0

#define configQUEUE_REGISTRY_SIZE                                   10

#define configUSE_QUEUE_SETS                                        0

#define configUSE_TIME_SLICING                                      0

#define configUSE_NEWLIB_REENTRANT                                  0

#define configENABLE_BACKWARD_COMPATIBILITY                         0

#define configNUM_THREAD_LOCAL_STORAGE_POINTERS                     5

#define configUSE_MINI_LIST_ITEM                                    1

#define configSTACK_DEPTH_TYPE                                      uint16_t

#define configMESSAGE_BUFFER_LENGTH_TYPE                            size_t

#define configHEAP_CLEAR_MEMORY_ON_FREE                             1


/* Memory allocation related definitions. */

#define configSUPPORT_STATIC_ALLOCATION                             1

#define configSUPPORT_DYNAMIC_ALLOCATION                            1

#define configTOTAL_HEAP_SIZE                                       ( ( size_t ) ( 8 * 1024 ) )

#define configAPPLICATION_ALLOCATED_HEAP                            0

#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP                   1


/* Hook function related definitions. */

#define configUSE_IDLE_HOOK                                 0

#define configUSE_TICK_HOOK                                 0

#define configCHECK_FOR_STACK_OVERFLOW                      0

#define configUSE_MALLOC_FAILED_HOOK                        0

#define configUSE_DAEMON_TASK_STARTUP_HOOK                  0

#define configUSE_SB_COMPLETED_CALLBACK                     0


/* Run time and task stats gathering related definitions. */

#define configGENERATE_RUN_TIME_STATS                       0

#define configUSE_TRACE_FACILITY                            0

#define configUSE_STATS_FORMATTING_FUNCTIONS                0


/* Co-routine related definitions. */

#define configUSE_CO_ROUTINES                               0

#define configMAX_CO_ROUTINE_PRIORITIES                     1


/* Software timer related definitions. */

#define configUSE_TIMERS                                    1

#define configTIMER_TASK_PRIORITY                           3

#define configTIMER_QUEUE_LENGTH                            10

#define configTIMER_TASK_STACK_DEPTH                        configMINIMAL_STACK_SIZE


/* added per tutorial */
/* IMPORTANT (also info for stm32) http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html */

#ifdef __NVIC_PRIO_BITS

  #define configPRIO_BITS                                   __NVIC_PRIO_BITS

#else

  #define configPRIO_BITS                                   4

#endif

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY             15

#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY        5


/* Interrupt nesting behaviour configuration. */

#define configKERNEL_INTERRUPT_PRIORITY         ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

#define configMAX_SYSCALL_INTERRUPT_PRIORITY    ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* FreeRTOS MPU specific definitions. */

#define configINCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS 0


/* Optional functions - most linkers will remove unused functions anyway. */

#define INCLUDE_vTaskPrioritySet                0

#define INCLUDE_uxTaskPriorityGet               0

#define INCLUDE_vTaskDelete                     0

#define INCLUDE_vTaskSuspend                    0

#define INCLUDE_vTaskDelayUntil                 0

#define INCLUDE_vTaskDelay                      1

#define INCLUDE_xTaskGetSchedulerState          0

#define INCLUDE_xTaskGetCurrentTaskHandle       0

#define INCLUDE_uxTaskGetStackHighWaterMark     0

#define INCLUDE_uxTaskGetStackHighWaterMark2    0

#define INCLUDE_xTaskGetIdleTaskHandle          0

#define INCLUDE_eTaskGetState                   0

#define INCLUDE_xTimerPendFunctionCall          0

#define INCLUDE_xTaskAbortDelay                 0

#define INCLUDE_xTaskGetHandle                  0

#define INCLUDE_xTaskResumeFromISR              0


/* A header file that defines trace macro can be included here. */

/* some stm relevant stuff from the tutorial */

#define vPortSVCHandler                         SVC_handler

#define xPortPendSVHandler                      pending_SV_handler

#define xPortSysTickHandler                     SysTick_handler


#endif /* FREERTOS_CONFIG_H */
