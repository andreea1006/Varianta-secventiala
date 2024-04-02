#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;
using namespace std::chrono;

int main(int argc, char** argv) {
    // Citirea imaginii
    Mat image = imread("poza1.jpg", IMREAD_COLOR);
    if (image.empty()) {
        cout << "Nu s-a putut incarca imaginea. Verifica daca calea este corecta." << endl;
        return -1;
    }

    // Măsurarea timpului de început
    auto start = high_resolution_clock::now();

    // Inversarea imaginii pe verticală
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols / 2; ++j) {
            Vec3b& pixel1 = image.at<Vec3b>(i, j);
            Vec3b& pixel2 = image.at<Vec3b>(i, image.cols - 1 - j);
            swap(pixel1, pixel2);
        }
    }

    // Măsurarea timpului de final
    auto stop = high_resolution_clock::now();

    // Calcularea timpului total de rulare
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Timpul total de rulare: " << duration.count() << " milisecunde." << endl;

    // Salvarea imaginii inverse
    imwrite("output_poza1.jpg", image);
    cout << "Imaginea a fost inversata si salvata cu succes." << endl;

    return 0;
}
