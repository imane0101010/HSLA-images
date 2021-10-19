# HSLA-images

Understanding the HSL Color Space
An image is generally represented by $N\times M \times 3$ tensor where the value of pixel is represented by the RGB color system. In this system a color is a linear combination of the three main colors red, green and blue. In this lab, we will use an alternative color space that represents colors by human perception of colors.

The HSL color system uses the Hue, Saturation and Luminance of the color. From the Adobe Techinag Guide page an brief explanation of each attribute is given as follow:

Hue ( denoted h) define the color itself, for example red in distinction to blue or yellow. The values of the hue axis run from $[0-360]$ beginning and ending with red and running through green, blue and all intermediary colors like greenish-blue, orange, purple, etc.

Saturation (denoted as s) indicates the degree to which the hue differs from a neutral gray. The values run from $0\%$, which is no color saturation, to $100\%$, which is the fullest saturation of a given hue at a given percentage of illumination.

Luminance (denoted as l) indicates the level of illumination.
The value values run as pecentenage $0\%$ appears black (no light) while $100/%$ is full illumination.

The full HSL color space is a three-dimensional space, but it is not a cube. The area truncates toward the two ends of the luminance axis and is widest in the middle rangel. The ellipsoid reveals several properties of the HSL colro space:

