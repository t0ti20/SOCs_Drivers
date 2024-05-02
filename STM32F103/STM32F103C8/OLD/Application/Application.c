
// Define UART1 peripheral registers addresses
#define USART1_BASE_ADDRESS 0x40013800
#define USART1_SR (*((volatile unsigned int*)(USART1_BASE_ADDRESS + 0x00)))
#define USART1_DR (*((volatile unsigned int*)(USART1_BASE_ADDRESS + 0x04)))
#define USART1_CR1 (*((volatile unsigned int*)(USART1_BASE_ADDRESS + 0x0C)))
#define USART1_CR2 (*((volatile unsigned int*)(USART1_BASE_ADDRESS + 0x10)))
#define USART1_CR3 (*((volatile unsigned int*)(USART1_BASE_ADDRESS + 0x14)))

// Define RCC peripheral registers addresses
#define RCC_BASE_ADDRESS 0x40021000
#define RCC_APB2ENR (*((volatile unsigned int*)(RCC_BASE_ADDRESS + 0x18)))

// Define NVIC peripheral registers addresses
#define NVIC_ISER ((volatile unsigned int*)0xE000E100)

// UART RXNE interrupt vector
#define USART1_IRQ_NUMBER 37

// Function prototypes
void USART1_IRQHandler(void);

// Global variable to store received data
volatile unsigned char rx_data;

int main() {
    // Enable clock for USART1 and GPIOA
    RCC_APB2ENR |= (1 << 2); // Enable USART1
    RCC_APB2ENR |= (1 << 2); // Enable GPIOA
    
    // Configure USART1 pins (PA9 as TX, PA10 as RX)
    // You need to configure GPIO pins as per your hardware setup
    
    // Configure USART1
    USART1_CR1 |= (1 << 5); // Enable RXNE interrupt
    
    NVIC_ISER[1] |= (1 << (USART1_IRQ_NUMBER - 32)); // Enable USART1 IRQ in NVIC
    
    // Enable USART1
    USART1_CR1 |= (1 << 13); // Enable USART1
    
    // Main loop
    while (1) {
        // Your main code here
    }
}

// USART1 interrupt handler
void USART1_IRQHandler(void) {
    if (USART1_SR & (1 << 5)) { // Check if RXNE flag is set
        rx_data = USART1_DR; // Read received data
        // Process received data as required
    }
}