<a href="http://cimg.eu">![Logo](http://cimg.eu/img/CImgLogo2.jpg)</a>
<h4><center><a href="http://cimg.eu">http://cimg.eu</a></center></h4>

The <font color="#000066">**CImg Library**</font> is a **small**, **open source**, and **modern C++ toolkit** for **image processing**, designed with these properties in mind:

![Usefulness](http://cimg.eu/img/item_usefulness.jpg) <font color="#000066">**CImg**</font> defines *classes* and *methods* to manage images in your own C++ code. You can use <font color="#000066">**CImg**</font> to load/save various file formats, access pixel values, display/transform/filter images, draw primitives (text, faces, curves, 3d objects, ...), compute statistics, manage user interactions on images, and so on...

![Genericity](http://cimg.eu/img/item_genericity.jpg) <font color="#000066">**CImg**</font> defines a single image class able to represent datasets having up to *4-dimensions* (from 1d scalar signals to 3d hyperspectral volumetric images), with *template pixel types* (<tt style="font-family:monospace;">bool,char,int,float,...</tt>). It also handles image *collections* and *sequences*.

![Portability](http://cimg.eu/img/item_portability.jpg) <font color="#000066">**CImg**</font> is *self-contained*, *thread-safe* and *highly portable*. It fully works on *different operating systems* (<tt style="font-family:monospace;">Unix,Windows,MacOS X,*BSD,...</tt>) and is compatible with *various C++ compilers* (<tt style="font-family:monospace;">Visual C++,g++,clang++,icc,...</tt>).

![Simplicity](http://cimg.eu/img/item_simplicity.jpg) <font color="#000066">**CImg**</font> is *lightweight*. It is made of a single header file <a href="https://raw.githubusercontent.com/dtschump/CImg/master/CImg.h"><tt style="font-family:monospace;">CImg.h</tt></a> that must be included in your C++ source. It defines only *four* different classes, encapsulated in the namespace <tt style="font-family:monospace;">cimg_library</tt>. It can be compiled using a minimal set of standard C++ and system libraries only. *No need for exotic or complex dependencies*.

![Extensibility](http://cimg.eu/img/item_extensibility.jpg) Although not mandatory, <font color="#000066">**CImg**</font> can use functionalities of external tools/libraries such as <a href="http://libboard.sourceforge.net/">Board</a>, <a href="http://ffmpeg.mplayerhq.hu/">FFMPEG</a>, <a href="http://www.fftw.org/">FFTW3</a>, <a href="http://www.graphicsmagick.org/">GraphicsMagick</a>, <a href="http://www.imagemagick.org/">ImageMagick</a>, <a href="http://www.netlib.org/lapack/">Lapack</a>, <a href="http://curl.haxx.se/libcurl/">libcurl</a>, <a href="http://www.ijg.org/">libjpeg</a>, <a href="http://www.libpng.org/pub/png/libpng.html">libpng</a>, <a href="http://www.libtiff.org/">libtiff</a>, <a href="http://www.imagemagick.org/Magick++/">Magick++</a>, <a href="http://www.openexr.com/">OpenEXR</a>, <a href="http://http://opencv.willowgarage.com/wiki/">OpenCV</a>, <a href="http://www.openmp.org/">OpenMP</a> or <a href="http://xmedcon.sourceforge.net/">XMedCon</a>. Moreover, a simple *plug-in* mechanism allows any user to directly enhance the library capabilities according to his needs.

![Freedom](http://cimg.eu/img/item_freedom.jpg) <font color="#000066">**CImg**</font> is a *free, open-source library* distributed under the <a href="http://www.cecill.info/licences/Licence_CeCILL-C_V1-en.txt">*CeCILL-C*</a> (close to the GNU LGPL) or <a href="http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt">*CeCILL*</a> (compatible with the GNU GPL) licenses. It can be used in commercial applications.

<blockquote>
  <font color="#000066">**CImg**</font> stands for <font color="#000066">**Cool Image**</font> : It is *easy to use*, *efficient* and is intended to be a very pleasant toolbox to design image processing algorithms in C++. Due to its generic conception, it can cover a wide range of image processing applications.
</blockquote>