#include "ASCII.h"

void begin::run() 
{
    /*std::cout << "where the Image is located (directory)" << '\n';
    std::cout << "->Cd :";
    std::cin >> this->directory;*/
    sayHello();
    loading();
}

void begin::sayHello() 
{
    std::string hello = "<><><><><><><><> Image -> ASCII <><><><><><><><>";
    for (char c : hello) {
        std::cout << c;
        Sleep(65);
    }
    std::cout << '\n';
}

void begin::loading()
{
    const char spinner[] = { '|', '/', '-', '\\' };
    const int numSpinnerFrames = sizeof(spinner) / sizeof(spinner[0]);
    const int numIterations = 15;
    const std::chrono::milliseconds delay(100);

    for (int i = 0; i < numIterations; ++i) {
        std::cout << "loading: " << spinner[i % numSpinnerFrames] << "\r";
        Sleep(delay.count());
    }

    std::cout << std::endl;
    //system("cls");
}

int solution::ImageToASCII()
{
    int scalar = 4;
    std::string GScal = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~i!lI;:,\"^`";
    std::ofstream ASCII;
    ASCII.open("ASCII.txt");
    cv::Mat img_cl = cv::imread(directory);
    cv::Mat img_gray;
    cv::cvtColor(img_cl, img_gray, cv::COLOR_BGR2GRAY);
    if (img_cl.empty()) {
        std::cerr << "Error loading image" << std::endl;
        return -1;
    }
    cv::imshow("colored", img_cl);
    cv::imshow("Gray", img_gray);
    for (int i = 0; i < img_gray.rows; i++) {
        std::string eachRow = "";
        for (int j = 0; j < img_gray.cols; j++) {
            int pix = (int)img_gray.at<uchar>(i, j);
            int all = ceil((GScal.length() - 1) * pix / 255);
            eachRow += GScal[all];
        }
        ASCII << eachRow << std::endl;
    }
    cv::waitKey(0);
    return 0;
}

int solution::calculateAVG(cv::Mat img, int rox, int colx, int scalr)
{
    int sum(0), r = rox, c = colx;
    int pixNum = 0;
    while (r <= r + scalr && r < img.rows) {
        while (c <= c + scalr && c < img.cols) {
            sum += (int)img.at<uchar>(c, r);
            pixNum++;
            c++;
        }
        r++;
    }
    return sum / pixNum;
}
