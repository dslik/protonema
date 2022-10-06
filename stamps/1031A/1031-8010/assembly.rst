********
Assembly
********

1031A assembly
**************

This assembly step takes 10 minutes.

.. tabularcolumns:: |>{\raggedright\arraybackslash}\Y{0.10}
                    |>{\raggedright\arraybackslash}\Y{0.70}
                    |>{\raggedright\arraybackslash}\Y{0.20}|

.. _tbl_1031_0B_assembly:

.. list-table:: 1031A assembly steps
    :class: longtable
    :header-rows: 1
    :align: center 

    * - Step #
      - Description
      - Signature/Stamp
    * - 1
      - Solder R1, R2 and D1 onto the 1031-0101 PCB.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_1.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with diodes and resistors soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 2
      - Solder U2 onto the 1031-0101 PCB.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_2.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with U2 soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 3
      - Using the 6 pin header, place and align the Pi Pico module.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_3.jpg
            :align:  center
            :figwidth: 100%
           
            Pi Pico module aligned on the 1031-0101 PCB.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 4
      - Solder the center DEBUG castellated pad on the far left of the Pi Pico module, then the two corner castellated pads on the far right.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_4.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with the debug and right corners of the Pi Pico module soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 5
      - Remove the 6 pin header, then solder the remainder of the castellated pads.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_5.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with Pi Pico module fully soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 6
      - Insert the 6 pin header into J6 from the front of the board, flip the board, and solder the header on, making sure it is 90 degrees to the board.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_6.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with J6 soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 7
      - Insert all four breadboard modules, then solder.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_7.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with all four breadboard modules soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 8
      - Insert the 4 pin header into J1 from the rear of the board, flip the board, and solder one pin of the header on, flip the board again and sure it is 90 degrees to the board, then solder the remaining three pins. Be careful not to touch the breadboard modules with the soldering iron.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_8.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with J1 soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 9
      - Insert the 2 pin header into J7 (Labelled as "3V3 OUTPUT ENABLE" on some revs) from the rear of the board, flip the board, and solder the header on, making sure it is 90 degrees to the board.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_9.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with J7 soldered on.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 10
      - Insert the jumper onto the 2 pin header.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_10.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with the jumper on J7.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}
    * - 11
      - For each of the four corner holes, attach a nylon screw to a nylon post through the hole.

        .. raw:: latex

          \vspace*{1ex}

        .. figure:: /images/step_11.jpg
            :align:  center
            :figwidth: 100%
           
            1031-0101 PCB with four nylon posts attached.
      - 
        .. raw:: latex

          \includegraphics[align=t,scale=1]{../../images/doc_stamp.pdf}

1031A programming
*****************

This assembly step takes 5 minutes.

.. tabularcolumns:: |>{\raggedright\arraybackslash}\Y{0.10}
                    |>{\raggedright\arraybackslash}\Y{0.70}
                    |>{\raggedright\arraybackslash}\Y{0.20}|

.. _tbl_1031_programming:

.. list-table:: 1031A programming steps
    :class: longtable
    :header-rows: 1
    :align: center 

    * - Step #
      - Description
      - Signature/Stamp
    * - 1
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
    * - 2
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
    * - 3
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
    * - 4
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
