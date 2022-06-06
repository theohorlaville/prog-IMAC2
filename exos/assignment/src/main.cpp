#include <p6/p6.h>
#include <iostream>
#include <vector>
#include "includes/menu.hpp"

//Les parties de code commentées sont le début de noughts and crosses

/*
void draw_board(int size, p6::Context& ctx)
{
    ctx.background({});
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ctx.fill = {1, 1, 1, 0.5};
            ctx.square(p6::TopRightCorner{(float)i * 0.4f, (float)j * 0.4f},
                       p6::Radius{0.2f});
        }
    }
}
*/
int main()
{
    display_menu();
    /*
    auto ctx   = p6::Context{{1000, 1000, "Noughts and Crosses"}};
    ctx.update = [&]() {
        ctx.background({.3f, 0.25f, 0.35f});
        ctx.stroke_weight = 0.01f;
        ctx.stroke        = {1.f, 1.f, 1.f, 1.f};
        ctx.fill          = {0.f, 0.f, 0.f, 0.f};
        draw_board(3, ctx);
    };
    ctx.start();
    */
}