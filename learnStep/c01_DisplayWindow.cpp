//
// Created by Shunli Han on 2023/2/10.
//

#include "c01_DisplayWindow.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    //初始化GLFW
    glfwInit();
    //使用glfwWindowHint函数来配置GLFW : (选项的名称,选项值)
    //主版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //次版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //核心模式
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //MacOS需要该命令
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    createWindow();
    return 0;
}

/**
 * 开始创建一个窗口
 */
int createWindow() {
    //宽 高 标题
    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    //Window 创建成功,通知GLFW将我们窗口的上下文设置为当前线程的主上下文
    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback_1);

    initGLAD();

    //渲染循环
    while (!glfwWindowShouldClose(window)) {
        //处理输入信息

        //渲染指令
        //状态设置函数: glClearColor用来设置清空屏幕所用的颜色
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        //状态使用函数: 执行清屏指令
        glClear(GL_COLOR_BUFFER_BIT);



        // 检查并调用事件，交换缓冲
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    //释放资源
    glfwTerminate();
    return 0;
}

/**
 * 初始化GLAD
 * GLAD是用来管理OpenGL的函数指针的，所以在调用任何OpenGL的函数之前我们需要初始化
 */

int initGLAD() {
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    return 0;
}

void framebuffer_size_callback_1(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}