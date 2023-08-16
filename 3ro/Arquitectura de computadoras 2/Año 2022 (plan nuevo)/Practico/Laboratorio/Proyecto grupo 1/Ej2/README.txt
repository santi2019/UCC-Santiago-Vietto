Arquitectura de computadoras II - Lab Rpi3

- Configuracion de pantalla: 512x512 pixeles, formato RGB 16 bits.
- El registro X0 contiene la direccion base del FrameBuffer (Pixel 1).
- El código de cada consigna debe ser escrito en los archivos app.s y gpio.s.
- El archivo main.s contiene la inicializacion del FrameBuffer, los GPIO y la llamada a app.s (NO EDITAR).
- El codigo de ejemplo pinta toda la pantalla de color ROJO puro. Luego lee la entrada del GPIO17, si el pulsador está liberado (IN=0V) la pantalla se pinta de azul y si se presiona (IN=3.3V) la pantalla se pinta de verde.
