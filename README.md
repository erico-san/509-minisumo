# 509 Minisumo 

En este repositorio se encuentra toda la información de diseño de un Minisumo Bluetooth de 12x12cm. Este modelo destaca por tener un chasis fabricado completamente en PLA, una cuchilla frontal intercambiable y un sistema de amortiguación independiente para los motores basado en caucho de silicona. 

A 3 celdas cuenta con una velocidad maxima de 1 m/s, recomendable practicar a esta velocidad para dominar en el dojo.

<img width="675" height="422" alt="Ensamble 3D de minisumo de PLA" src="https://github.com/user-attachments/assets/581d4a22-8805-420d-b18b-9ebada26e92a" />

## Archivos CAD

* **Ensamble general y piezas:** [Ver en Onshape](https://cad.onshape.com/documents/9d2ecc8a8a06794e88858b61/w/4d3c07dad9eb52e24bca0cad/e/eb328988e087dcca06bbb127)

<img width="526" height="440" alt="Vista explosiva chasis minisumo PLA" src="https://github.com/user-attachments/assets/0aeb5609-a8c2-41c4-b3d5-cc04569b077c" />

## Componentes y Materiales

**Electrónica y Mecánica:**
* [Motorreductores verdes 48:1 Chihai CHF-T130](https://es.aliexpress.com/item/1005010205937236.html) (Se pueden reemplazar por los clásicos [motorreductores amarillos 48:1](https://es.aliexpress.com/item/1005004350962451.html?spm=a2g0o.productlist.main.1.6706QxRxQxRx4g&algo_pvid=fedc05f4-c0cb-4b12-b750-d333e8cedc31&algo_exp_id=fedc05f4-c0cb-4b12-b750-d333e8cedc31-0&pdp_ext_f=%7B%22order%22%3A%22181%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21PEN%217.79%217.79%21%21%212.24%212.24%21%402103138417895703661075654e0c8c%2112000028860459502%21sea%21PE%212052306243%21X%211%210%21n_tag%3A-29919%3Bd%3Ab20312be%3Bm03_new_user%3A-29895&curPageLogUid=3RgEN6Oig0UC&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005004350962451%7C_p_origin_prod%3A)).
* [Batería Gaoneng 3S 11.1V 300mAh](https://es.aliexpress.com/item/1005006010618131.html).
* [Tiras de plomo de 7mm para añadir peso](https://es.aliexpress.com/item/1005005885246156.html) (Opcional, manipular bajo su propio riesgo por tratarse de plomo).

**Tornillería:**
* [Tornillos M2x6](https://es.aliexpress.com/item/1005004177352184.html).
* [2 und M3x23 y 2 und M3x4](https://es.aliexpress.com/item/1005012581596315.html).

**Fabricación (Impresión 3D y Moldes):**
* **Caucho de silicona Shore A20** para las llantas y los amortiguadores. 
  * *Opción local (Lima, Perú):* [RTV Tipo 5 Plus (Silika Moldes)](https://silikamoldeseinsumos.pe/producto/caucho-de-silicona-rtv-tipo-5-plus-1kg/).
  * *Opción internacional:* [Aliexpress (No probada, dureza sin confirmar)](https://es.aliexpress.com/item/1005010538060521.html).
* [Filamento ePLA-HS eSUN de 1.75mm](https://digitalz3d.com/producto/filamento-3d-epla-hs-1-75mm-1kg-esun/). Se requieren aproximadamente 120gr para el chasis del minisumo y 50gr adicionales para los moldes. *Nota: Solo se necesita imprimir un molde de llantas para fabricar dos; el cilindro interno se debe recortar usando el espaciador impreso*.

## Detalles Técnicos

### Distribución de peso (Centro de Masa)

El robot tiene un peso total de 498 gr (rozando el límite reglamentario). Su diseño ubica el centro de masa por debajo del eje central de las ruedas. Esta configuración geométrica es crucial porque evita que el robot tienda a levantarse durante aceleraciones bruscas, manteniendo la rampa siempre con adherencia al tatami.

<img width="500" height="314" alt="Analisis de centro de masa en robot minisumo" src="https://github.com/user-attachments/assets/adc51c55-0537-4b74-b257-df201b7ecf7e" />

### Amortiguadores de silicona independientes

Los motores no están fijados rígidamente al chasis. Cada motor cuenta con un eje de giro propio y se apoya sobre una almohadilla de caucho de silicona (los moldes para fabricarlas están incluidos en el repositorio). 

Esto permite un desplazamiento angular interno independiente para cada motor. El propósito principal de este mecanismo es absorber las irregularidades del suelo o de las propias llantas, evitando que esas vibraciones mecánicas se transmitan al chasis y levanten la cuchilla frontal.

<img width="500" height="281" alt="Diagrama de amortiguador de silicona para motores" src="https://github.com/user-attachments/assets/1181647f-d449-4fe3-b5cf-2cc4851056a0" />
<img width="500" height="295" alt="Corte transversal amortiguador interno minisumo" src="https://github.com/user-attachments/assets/68a2fe52-1472-497c-9a92-8aaae4bb6018" />

## Control por Bluetooth

Para el control manual de este modelo (en base a la versión 505) se utiliza la aplicación **Bluetooth RC Car** para Android.

* **Descarga:** [Bluetooth RC Car en Softonic](https://bluetooth-rc-car.softonic.com/android).

<img width="481" height="362" alt="App Android Bluetooth RC Car para control de minisumo" src="https://github.com/user-attachments/assets/1752ba2e-0293-4d04-9ad2-65c4749037eb" />

## Electrónica (Main Board)

La placa PCB diseñada para este modelo integra los componentes necesarios para manejar alta potencia en un espacio reducido:

* **Microcontrolador:** [ESP32 WROOM](https://es.aliexpress.com/item/1005009235650481.html?spm=a2g0o.order_list.order_list_main.110.312c194drjBazP&gatewayAdapt=glo2esp).
* **Regulación de voltaje:** [Módulo DC-DC a 5V (Capacidad máxima de 3A)](https://es.aliexpress.com/item/1005005393995240.html?spm=a2g0o.order_list.order_list_main.105.312c194drjBazP&gatewayAdapt=glo2esp).
* **Drivers de motor:** Se utilizan circuitos integrados de medio puente H [**BTN7960**](https://es.aliexpress.com/item/1005008173352053.html?spm=a2g0o.order_list.order_list_main.5.312c194drjBazP&gatewayAdapt=glo2esp) para el control de dirección y potencia de los motores. *(Nota técnica: Estos componentes soportan voltajes de operación de hasta 27V y picos de corriente de hasta 43A, asegurando que los motores Chihai trabajen sin problemas térmicos ni bloqueos)*.

**Esquemático:**

<img width="789" height="394" alt="Esquematico PCB Minisumo ESP32 y BTN7960" src="https://github.com/user-attachments/assets/1b9bd535-38a9-44ac-8293-24672f5fd735" />

**Diseño de la Placa (Layout):**

<img width="498" height="371" alt="Layout Top PCB Minisumo" src="https://github.com/user-attachments/assets/f8777850-a29b-4728-8a9d-fee2abcc36a4" />

<img width="491" height="362" alt="Layout Bottom PCB Minisumo" src="https://github.com/user-attachments/assets/3fa7bb15-a88e-481a-a004-e7d65eac65d1" />

## Videos Adjuntos

<table>
  <tr>
    <td align="center">
      <a href="https://youtube.com/shorts/eMg-vKGihfI">
        <img src="https://img.youtube.com/vi/eMg-vKGihfI/0.jpg" width="250" alt="Video de prueba pesaje de minisumo" />
      </a>
      <br><b>Pesaje oficial</b>
    </td>
    <td align="center">
      <a href="https://youtube.com/shorts/Ilnm2QnsiVM">
        <img src="https://img.youtube.com/vi/Ilnm2QnsiVM/0.jpg" width="250" alt="Video de combate minisumo en competencia" />
      </a>
      <br><b>Combate en competencia</b>
    </td>
  </tr>
</table>
