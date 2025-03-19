/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (3)
#endif
/* ISR prototypes */
void ctsu_write_isr(void);
void ctsu_read_isr(void);
void ctsu_end_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_CTSU_WRITE ((IRQn_Type) 0) /* CTSU WRITE (Write request interrupt) */
#define CTSU_WRITE_IRQn          ((IRQn_Type) 0) /* CTSU WRITE (Write request interrupt) */
#define VECTOR_NUMBER_CTSU_READ ((IRQn_Type) 1) /* CTSU READ (Measurement data transfer request interrupt) */
#define CTSU_READ_IRQn          ((IRQn_Type) 1) /* CTSU READ (Measurement data transfer request interrupt) */
#define VECTOR_NUMBER_CTSU_END ((IRQn_Type) 2) /* CTSU END (Measurement end interrupt) */
#define CTSU_END_IRQn          ((IRQn_Type) 2) /* CTSU END (Measurement end interrupt) */
#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
