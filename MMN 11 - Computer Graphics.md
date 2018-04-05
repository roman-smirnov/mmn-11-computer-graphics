# MMN 11 - Computer Graphics

Roman Smirnov

## Question 1

### A

The screen is 8"x10" - for a total display area of 80 square inches. The pixel density is 100x100 pixels per inch - 10,000 pixels per square inch. Thus, the given display has a total of 80x10,000 = 800k pixels. Given the frame buffer holds 6 bits per pixel - it holds a total of 4.8 Mbits or 0.6 Mbytes.

### B

At a resolution of 640x480, with 12 bits per pixel, the total information needed to be transferred is 3686400 bits. Therefore, at the specified rate of 10^5 bits/sec, 36.864 seconds are needed to fully load the frame buffer. 

At a resolution of 1280x1024, with 24 bits per pixel at the frame buffer and the same transfer bitrate, it will take 314.5728 seconds to load the image data into the buffer.

## Question 2

### A

Given the refresh rate is $r$ frames per second, then the refresh time is $t_r = 1/r$ seconds. There are $m$ scan lines with a retrace time of $t_h$ per scan line. Consequentially, the total horizontal retrace time is $t_h \times m$. Moreover, there's also a single vertical retrace per frame, which takes $t_v$ time. Finally, we can express the retrace time as a fraction of total refresh time 

$$ R_{retrace} = \frac{m \times t_h + t_v}{t_r} $$

### B

Refresh rate is 50hz (20 milliseconds per frame). Vertical retrace time is 20 microseconds. Horizontal retrace time is 4 microseconds. Resolution of 640x480.

#### Non-Interlaced

$time_{retrace} = 480 \times 4 \times 10^{-6} + 20 \times 10^{-6} = 0.00194 \ sec = 1.94 \ millisec$ 

$ time_{per-pixel} = {0.020 - 0.00194 \over 480 \times 640} = 0.578 \ nsec$

#### Interlaced

$time_{retrace} = \frac{480}{2} \times 4 \times 10^{-6} + 20 \times 10^{-6} = 0.00098 \ sec = 0.98 \ millisec$ 

$ time_{per-pixel} = {0.020 - 0.00098 \over 240  \times 640} = 0.123 \ \mu sec$



## Question 3

### A

Use-case specific programs are a higher abstraction over the general graphics frameworks meant for programmers. The latter require utilizing primitive format and operations (bits, bytes, linear algebra, etc) while the former usually deal with abstract concepts and operations (shapes, colors, texture, spatial position, etc).

### B

For 1024x768 the aspect ratio is 4:3. Conesquentially, reducing the horizontal resolution to 640 pixels and keeping the same aspect ratio result in a vertical resolution of $640 \times {3 \over 4} = 480$.

### C

1. We'll perform a reflection transform over the  horizontal axis. 
2. We'll perform a translation transform to at the negative y axis direction of magnitue equal to screen height. 

Therefore, the change of representation can be represented by an affine transform as follows:

$$ (x',y')^t =   \begin{bmatrix} 1 & 0 \\ 0 & -1 \end{bmatrix} \cdot (x,y)^t + (0, \text{window_height})^t $$

### Question 4

### NOTES

#### Build

I don't currently have access to a Windows system. I've attached the cmake file, it should be cross-platform. Sorry, will try to come up with a solution going forward. 

#### Shapes

The stars are made up of points, triangles, quads. They don't change shape when resized. 

![Screen Shot 2018-04-05 at 18.14.52](MMN 11 - Computer Graphics.assets/Screen Shot 2018-04-05 at 18.14.52.png)

