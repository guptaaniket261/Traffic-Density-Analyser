## Steps to run the code of Part1:

1. Clone this repository using `git clone https://github.com/aayushgoyal443/COP290Assignment1` or download as Zip and extract.
2. To run the code, open the Directory in which **Assignment1.cpp** file is present.
3. Put the images whose perspective or view needs to be changed in the same directory as Assignment1.cpp
4. Build and install OpenCV in your machine if you already haven't. Here are guides to do the same:
    * [For Ubuntu](http://techawarey.com/programming/install-opencv-c-c-in-ubuntu-18-04-lts-step-by-step-guide/) 
    * [For Windows](https://cv-tricks.com/how-to/installation-of-opencv-4-1-0-in-windows-10-from-source/)
    * [For MacOS](https://docs.opencv.org/master/d0/db2/tutorial_macos_install.html)
5. Launch the terminal in that directory.
6. Give the `make allpart1` command. This should produce a binary file named "part1" in the same directory.  
(Make sure the **Makefile** is present in the directory)
7. Now run the command `./part1 <file_name>` . Replace <file_name> with the name of your image file.
8. If your image file is empty an exception will be raised, otherwise a window named "Original Image" will open.
9. Click 4 points on this window to choose the points about which you want to change the Homography.  
(You don't need to worry about the order in which you choose the points, **the code automatically arranges them in the required order**)
10. You should see 2 new windows on the screen namely, "Projected Image" and "Cropped Image". These images also get saved in the same directory.
11. Press Escape key to close the windows.
12. Run `make clean` to delete the part1 file.

    **Note:** while changing the homography of an image, you will need to change the values of destination points in the Assignment1.cpp file. 
    This can be done by changing the values stored in the 'a' vector in line 109.
    
## Steps to run the code of Part2:
1. To run the code, open the Directory in which **assignment1_2.cpp** file is present.
2. Put the videos whose Queue Density and Dynamic Density needs to be found in the same directory as assignment1_2.cpp
3. Launch terminal in that directory.
4. Give the `make allpart2` command. This should produce a binary file named "part2" in the same directory.  
(Make sure the **Makefile** is present in the directory)
5. Now run the command `./part2 <file_name>` . Replace <file_name> with the name of your video file.
6. **You should see the output in a "out.txt" file.** This out.txt has three entries namely Frame number, Queue density, Dynamic density which denote the respective values in this order.
7. Run `make clean` to delete the part2 file.
