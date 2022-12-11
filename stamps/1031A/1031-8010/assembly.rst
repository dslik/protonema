********
Assembly
********

:math:`\constProdNum` assembly
******************************

This assembly step takes 10 minutes.

.. tabularcolumns:: |>{\raggedright\arraybackslash}\Y{0.10}
                    |>{\raggedright\arraybackslash}\Y{0.70}
                    |>{\raggedright\arraybackslash}\Y{0.20}|

.. _tbl_assembly_1:

.. list-table:: :math:`\constProdNum` assembly steps
    :class: longtable
    :header-rows: 1
    :align: center 

    * - Step #
      - Description
      - Signature/Stamp
    * - 4.1.1
      - Solder R1, R2 and D1 onto the 1031-0101 PCB.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_4_1_1.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with diodes and resistors soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.1.2
      - Solder U2 onto the 1031-0101 PCB.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_4_1_2.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with U2 soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.1.3
      - Using the 6 pin header, place and align the Pi Pico module.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_4_1_3.jpg
            :align:  center
            :figwidth: 100%
           
            Pi Pico module aligned on the 1031-0101 PCB.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.1.4
      - Solder the center DEBUG castellated pad on the far left of the Pi Pico module, then the two corner castellated pads on the far right.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_4_1_4.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with the debug and right corners of the Pi Pico module soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.1.5
      - Remove the 6 pin header, then solder the remainder of the castellated pads.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_4_1_5.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with Pi Pico module fully soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.1.6
      - Insert the 6 pin header into J6 from the front of the board, flip the board, and solder the header on, making sure it is 90 degrees to the board.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_4_1_6.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with J6 soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.1.7
      - Solder U3 onto the 1031-0101 PCB.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_4_1_7.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with U3 soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.1.8
      - Insert all four breadboard modules, then solder.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_4_1_8.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with all four breadboard modules soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.1.9
      - Insert the 4 pin header into J1 from the rear of the board, flip the board, and solder one pin of the header on, flip the board again and sure it is 90 degrees to the board, then solder the remaining three pins. Be careful not to touch the breadboard modules with the soldering iron.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_4_1_9.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with J1 soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.1.10
      - Insert the 2 pin header into JP1 (Labelled as "3V3 OUTPUT ENABLE"¥) from the rear of the board, flip the board, and solder the header on, making sure it is 90 degrees to the board. Be careful not to touch the breadboard modules with the soldering iron.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_4_1_10.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with JP1 soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.1.11
      - Insert the jumper onto the 2 pin JP1 header.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_4_1_11.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with the jumper on JP1.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.1.12
      - For each of the four corner holes, attach a nylon screw to a nylon post through the hole.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_4_1_12.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with four nylon posts attached.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}

:math:`\constProdNum` programming
*********************************

This assembly step takes 5 minutes.

.. tabularcolumns:: |>{\raggedright\arraybackslash}\Y{0.10}
                    |>{\raggedright\arraybackslash}\Y{0.70}
                    |>{\raggedright\arraybackslash}\Y{0.20}|

.. _tbl_assembly_2:

.. list-table:: :math:`\constProdNum` programming steps
    :class: longtable
    :header-rows: 1
    :align: center 

    * - Step #
      - Description
      - Signature/Stamp
    * - 4.2.1
      - Connect the programming cable connected to the 1031A programmer to the USB connector on the Pi Pico module on the 1031A board.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/fpo_table.pdf
            :align:  center
            :figwidth: 100%
           
            Programmer connected to the 1031A board
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.2.2
      - Connect the USB to Micro USB cable to the workstation USB power adapter and the 1031A programmer. Verify that the screen turns on.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/fpo_table.pdf
            :align:  center
            :figwidth: 100%
           
            Powered up programmer.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.2.3
      - Wait for two minutes for the programmer to start up and program the 1031A. The LED on the 1031A Pi Pico module will start blinking once successfully programmed.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/fpo_table.pdf
            :align:  center
            :figwidth: 100%
           
            1031A blinking after being programmed.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4.2.4
      - Disconnect the power USB connector from the programmer, then disconnect the programmer from the now programmed 1031A.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/fpo_table.pdf
            :align:  center
            :figwidth: 100%
           
            Programmed 1031A
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
