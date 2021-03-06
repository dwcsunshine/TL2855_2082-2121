/* generated vector header file - do not edit */
        #ifndef VECTOR_DATA_H
        #define VECTOR_DATA_H
                /* Number of interrupts allocated */
        #ifndef VECTOR_DATA_IRQ_COUNT
        #define VECTOR_DATA_IRQ_COUNT    (16)
        #endif
        /* ISR prototypes */
        void ctsu_write_isr(void);
        void ctsu_read_isr(void);
        void ctsu_end_isr(void);
        void gpt_counter_overflow_isr(void);
        void spi_rxi_isr(void);
        void spi_txi_isr(void);
        void spi_tei_isr(void);
        void spi_eri_isr(void);
        void dmac_int_isr(void);
        void sci_uart_rxi_isr(void);
        void sci_uart_txi_isr(void);
        void sci_uart_tei_isr(void);
        void sci_uart_eri_isr(void);
        void fcu_frdyi_isr(void);
        void fcu_fiferr_isr(void);

        /* Vector table allocations */
        #define VECTOR_NUMBER_CTSU_WRITE ((IRQn_Type) 0) /* CTSU WRITE (Write request interrupt) */
        #define VECTOR_NUMBER_CTSU_READ ((IRQn_Type) 1) /* CTSU READ (Measurement data transfer request interrupt) */
        #define VECTOR_NUMBER_CTSU_END ((IRQn_Type) 2) /* CTSU END (Measurement end interrupt) */
        #define VECTOR_NUMBER_GPT0_COUNTER_OVERFLOW ((IRQn_Type) 3) /* GPT0 COUNTER OVERFLOW (Overflow) */
        #define VECTOR_NUMBER_SPI0_RXI ((IRQn_Type) 4) /* SPI0 RXI (Receive buffer full) */
        #define VECTOR_NUMBER_SPI0_TXI ((IRQn_Type) 5) /* SPI0 TXI (Transmit buffer empty) */
        #define VECTOR_NUMBER_SPI0_TEI ((IRQn_Type) 6) /* SPI0 TEI (Transmission complete event) */
        #define VECTOR_NUMBER_SPI0_ERI ((IRQn_Type) 7) /* SPI0 ERI (Error) */
        #define VECTOR_NUMBER_DMAC0_INT ((IRQn_Type) 8) /* DMAC0 INT (DMAC transfer end 0) */
        #define VECTOR_NUMBER_GPT1_COUNTER_OVERFLOW ((IRQn_Type) 9) /* GPT1 COUNTER OVERFLOW (Overflow) */
        #define VECTOR_NUMBER_SCI2_RXI ((IRQn_Type) 10) /* SCI2 RXI (Received data full) */
        #define VECTOR_NUMBER_SCI2_TXI ((IRQn_Type) 11) /* SCI2 TXI (Transmit data empty) */
        #define VECTOR_NUMBER_SCI2_TEI ((IRQn_Type) 12) /* SCI2 TEI (Transmit end) */
        #define VECTOR_NUMBER_SCI2_ERI ((IRQn_Type) 13) /* SCI2 ERI (Receive error) */
        #define VECTOR_NUMBER_FCU_FRDYI ((IRQn_Type) 14) /* FCU FRDYI (Flash ready interrupt) */
        #define VECTOR_NUMBER_FCU_FIFERR ((IRQn_Type) 15) /* FCU FIFERR (Flash access error interrupt) */
        typedef enum IRQn {
            Reset_IRQn = -15,
            NonMaskableInt_IRQn = -14,
            HardFault_IRQn = -13,
            MemoryManagement_IRQn = -12,
            BusFault_IRQn = -11,
            UsageFault_IRQn = -10,
            SecureFault_IRQn = -9,
            SVCall_IRQn = -5,
            DebugMonitor_IRQn = -4,
            PendSV_IRQn = -2,
            SysTick_IRQn = -1,
            CTSU_WRITE_IRQn = 0, /* CTSU WRITE (Write request interrupt) */
            CTSU_READ_IRQn = 1, /* CTSU READ (Measurement data transfer request interrupt) */
            CTSU_END_IRQn = 2, /* CTSU END (Measurement end interrupt) */
            GPT0_COUNTER_OVERFLOW_IRQn = 3, /* GPT0 COUNTER OVERFLOW (Overflow) */
            SPI0_RXI_IRQn = 4, /* SPI0 RXI (Receive buffer full) */
            SPI0_TXI_IRQn = 5, /* SPI0 TXI (Transmit buffer empty) */
            SPI0_TEI_IRQn = 6, /* SPI0 TEI (Transmission complete event) */
            SPI0_ERI_IRQn = 7, /* SPI0 ERI (Error) */
            DMAC0_INT_IRQn = 8, /* DMAC0 INT (DMAC transfer end 0) */
            GPT1_COUNTER_OVERFLOW_IRQn = 9, /* GPT1 COUNTER OVERFLOW (Overflow) */
            SCI2_RXI_IRQn = 10, /* SCI2 RXI (Received data full) */
            SCI2_TXI_IRQn = 11, /* SCI2 TXI (Transmit data empty) */
            SCI2_TEI_IRQn = 12, /* SCI2 TEI (Transmit end) */
            SCI2_ERI_IRQn = 13, /* SCI2 ERI (Receive error) */
            FCU_FRDYI_IRQn = 14, /* FCU FRDYI (Flash ready interrupt) */
            FCU_FIFERR_IRQn = 15, /* FCU FIFERR (Flash access error interrupt) */
        } IRQn_Type;
        #endif /* VECTOR_DATA_H */