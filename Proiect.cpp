#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    // Citirea imaginii
    Mat image = imread("poza1.jpg", IMREAD_COLOR);
    if (image.empty()) {
        cout << "Nu s-a putut incarca imaginea. Verifica daca calea este corecta." << endl;
        return -1;
    }

    // Inversarea imaginii pe verticală
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols / 2; ++j) {
            Vec3b& pixel1 = image.at<Vec3b>(i, j);
            Vec3b& pixel2 = image.at<Vec3b>(i, image.cols - 1 - j);
            swap(pixel1, pixel2);
        }
    }

    // Salvarea imaginii inverse
    imwrite("output_poza1.jpg", image);
    cout << "Imaginea a fost inversata si salvata cu succes." << endl;

    return 0;
}
