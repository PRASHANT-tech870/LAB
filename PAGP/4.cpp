#include <iostream>
#include <cstdlib>
#include <gd.h>
#include <omp.h>
#include <cstring> // For strcmp

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <in.png or in.jpeg> <out.png or out.jpeg>" << endl;
        exit(1);
    }

    FILE *ifp = fopen(argv[1], "rb");
    if (ifp == NULL) {
        cout << "Error: Unable to open input file!" << endl;
        exit(1);
    }
    
    FILE *ofp = fopen(argv[2], "wb");
    if (ofp == NULL) {
        cout << "Error: Unable to open output file!" << endl;
        exit(1);
    }

    double t = omp_get_wtime();

    // Detect file type and read accordingly (JPEG or PNG)
    gdImagePtr img = nullptr;
    if (strstr(argv[1], ".png")) {
        img = gdImageCreateFromPng(ifp);  // Read PNG
    } else if (strstr(argv[1], ".jpeg") || strstr(argv[1], ".jpg")) {
        img = gdImageCreateFromJpeg(ifp);  // Read JPEG
    } else {
        cout << "Unsupported image format!" << endl;
        exit(1);
    }

    if (img == nullptr) {
        cout << "Error loading image!" << endl;
        fclose(ifp);
        fclose(ofp);
        exit(1);
    }

    int w = gdImageSX(img);
    int h = gdImageSY(img);
    cout << "Image loaded successfully. Width: " << w << ", Height: " << h << endl;

    #pragma omp parallel for
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            int color = gdImageGetPixel(img, x, y);
            int avgColor = (gdImageRed(img, color) + gdImageGreen(img, color) + gdImageBlue(img, color)) / 3;
            color = gdImageColorAllocate(img, avgColor, avgColor, avgColor);
            #pragma omp critical
            gdImageSetPixel(img, x, y, color);
        }
    }

    // Save the processed image (write in the same format as input)
    if (strstr(argv[2], ".png")) {
        gdImagePng(img, ofp);  // Save as PNG
    } else if (strstr(argv[2], ".jpeg") || strstr(argv[2], ".jpg")) {
        gdImageJpeg(img, ofp, 100);  // Save as JPEG with 100 quality
    } else {
        cout << "Unsupported output format!" << endl;
        gdImageDestroy(img);
        fclose(ifp);
        fclose(ofp);
        exit(1);
    }

    gdImageDestroy(img);
    fclose(ifp);
    fclose(ofp);

    t = omp_get_wtime() - t;
    cout << "Time: " << t << endl;
}


// sudo apt install libgd-dev
// g++ 4.cpp -fopenmp -lgd
// ./a.out test4.png output.png
