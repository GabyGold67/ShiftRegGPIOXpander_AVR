# GPIO Digital Outputs Expander Library (ShiftRegGPIOXpander_AVR)  

## [Complete library documentation HERE!](https://gabygold67.github.io/ShiftRegGPIOXpander_AVR/)

## The main concepts driving this development are:
   - Easy output pins addition to a project without making substantial changes to the standard programming practices referring to output pin values writes and reads.  
   - Methods and resources are provided to minimize full outputs updating, usually associated with the nature of the GPIO expanders based on SIPO shift registers without preset size limits (changes buffering).
   - Pin state reading consistency, even for buffered changes.
   - Easily extend the number of output pins by adding Shift Registers modules, and just changing an instantiation parameter.  
   - A number of services added to manage the new extra pins:
      - Pin state toggling
      - Setting, resetting and toggling several pins indicated by providing a mask.
      - Virtual Ports construction and management as independent units for easy devices management, with the required API to provide usual internal ports management.  

---  
## Fast Setup:
- Connect as many shift registers as you'll need in daisy chain configuration. Consider you'll be connecting the first shift register to the MCU, that will take 3 available output pins, and give you 8, making that a net addition of 5 output pins to your resources. For each following shift register connected to the daisy chain you'll get 8 extra pins.  

- Create a ShiftRegGPIOXpander object using the pin numbers connected to the first shift register of the chain and the quantity of shift registers connected in that daisy chain (the minimum value admitted is **1**).
`ShiftRegGPIOXpander mySrgx(ds, sh_cp, st_cp, srQty);`

- Initiate the ShiftRegGPIOXpander object by using the `.begin()` method, as simple as: `mySrgx.begin();`

- Start using the ShiftRegGPIOXpander object as normal MCU pins, setting pins value with the `mySrgx.digitalWriteSr(pinToModify, LOW);` and `mySrgx.digitalWriteSr(pinToModify, HIGH);`.

- The current pin setting might be checked by using `mySrgx.digitalReadSr(pinToRead);`, but remember: all the ShiftRegGPIOXpander pins are set to **Outputs**.

In short:
```
ShiftRegGPIOXpander mySrgx(ds, sh_cp, st_cp, srQty);
mySrgx.begin();
mySrgx.digitalWriteSr(pinToModify, HIGH);
```
You then have a plethora of methods to use for managing the **ShiftRegGPIOXpander** pins.

---  
   **Note:**  
   I will agree with anybody who catalogs this as a **YAUSRL** (Yet Another Unneeded Shift Register Library). The thing is I tried to find an adequate library for my project but I failed to find something I felt comfortable working with. 