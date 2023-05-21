import java.awt.*;
import java.awt.image.*;
import java.util.*;
import javax.swing.*;

class Assignment1_62050188_62050198 extends JPanel{
    public static Image image ;

    public static void main(String[] args){
        Assignment1_62050188_62050198 m = new Assignment1_62050188_62050198();
        JFrame f = new JFrame();
        f.add(m);
        f.setTitle("ArtStyle");
        f.setSize(600 ,600);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
    public void paint(Graphics g){
        BufferedImage buffer = new BufferedImage(601, 601, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g2 = buffer.createGraphics();

        g2.setColor(Color.WHITE);
        g2.fillRect(0, 0, 600, 600);

        g2.setColor(Color.BLACK);
        draw_line(g2 ,415, 43, 412, 580);
        draw_line(g2 ,412, 580, 400, 581);
        draw_line(g2 ,400, 581, 388, 561);
        draw_line(g2 ,403, 43, 401, 581);
        draw_line(g2 ,389, 155, 388, 561);
        draw_line(g2 ,387, 523, 274, 363);
        draw_line(g2 ,387, 557, 274, 377);
        draw_line(g2 ,389, 124, 390, 56);
        draw_line(g2 ,413, 359, 440, 359);
        draw_line(g2 ,413, 389, 440, 389);
        draw_line(g2 ,439, 359, 454, 364);
        draw_line(g2 ,439, 389, 454, 395);
        draw_line(g2, 440, 390, 437, 578);
        draw_line(g2 ,456, 140, 454, 599);
        draw_line(g2 ,456, 140, 563, 93);
        draw_line(g2 ,460, 159, 501, 144);
        draw_line(g2 ,460, 159, 459, 337);
        draw_line(g2 ,459, 337, 499, 351);
        draw_line(g2 ,499, 351, 501, 144);
        draw_line(g2 ,510, 117, 504, 599);
        draw_line(g2 ,516, 140, 562, 120);
        draw_line(g2 ,516, 140, 513, 357);
        draw_line(g2 ,513, 357, 560, 371);
        draw_line(g2 ,564, 0, 558, 504);
        draw_line(g2 ,558, 498, 542, 499);
        draw_line(g2 ,541, 500, 600, 543);
        draw_line(g2 ,541, 500, 540, 572);
        draw_line(g2 ,540, 572, 570, 599);
        draw_line(g2 ,558, 587, 557, 599);
        draw_line(g2 ,559, 504, 599, 532);
        draw_line(g2 ,501, 364, 506, 366);
        draw_line(g2 ,501, 364, 500, 433);
        draw_line(g2 ,500, 433, 506, 437);
        draw_line(g2 ,506, 437, 506, 366);
        draw_line(g2 ,388, 351, 356, 336);
        draw_line(g2 ,388, 380, 356, 360);
        draw_line(g2 ,351, 333, 322, 318);
        draw_line(g2 ,351, 355, 322, 337);
        draw_line(g2 ,322, 128, 322, 429);
        draw_line(g2 ,318, 133, 318, 424);
        draw_line(g2 ,318, 316, 299, 307);
        draw_line(g2 ,318, 334, 299, 322);
        draw_line(g2 ,299, 153, 299, 397);
        draw_line(g2 ,296, 158, 296, 392);
        draw_line(g2 ,296, 305, 284, 298);
        draw_line(g2 ,296, 321, 284, 311);
        draw_line(g2 ,284, 170, 284, 375);
        draw_line(g2 ,282, 171, 282, 372);
        draw_line(g2, 282, 297, 279, 295);
        draw_line(g2, 282, 311, 279, 309);
        draw_line(g2 ,413, 538, 436, 535);
        draw_line(g2 ,436, 535, 454, 549);
        draw_line(g2 ,413, 579, 435, 578);
        draw_line(g2 ,435, 578, 454, 600);
        draw_line(g2 ,348, 125, 348, 152);
        draw_line(g2 ,349, 125, 390, 125);
        draw_line(g2 ,391, 154, 391, 124);
        draw_line(g2 ,348, 152, 391, 152);
        draw_line(g2 ,391, 124, 396, 121);
        draw_line(g2 ,397, 120, 397, 156);
        draw_line(g2 ,397, 156, 395, 158);
        draw_line(g2 ,395, 158, 391, 156);
        draw_line(g2 ,394, 157, 394, 123);
        // //ป้ายห้อย
        draw_line(g2, 356, 124, 356, 93);
        draw_line(g2 ,356, 478, 356, 154);
        draw_line(g2, 351, 124, 351, 98);
        draw_line(g2 ,351, 470, 352, 155);
        draw_line(g2 ,402, 43, 274, 179);
        //เส้นประตู
        draw_line(g2 ,401, 43, 401, 0);
        draw_line(g2 ,443, 44, 441, 360);
        draw_line(g2 ,445, 43, 503, 0);
        draw_line(g2 ,402, 42, 444, 44);
        draw_line(g2 ,419, 42, 472, 0);
        //เส้นบนประตู
        draw_line(g2 ,400, 0, 274, 164);
        draw_line(g2 ,78, 158, 274, 161);
        draw_line(g2 ,79, 128, 278, 136);
        draw_line(g2 ,278, 136, 365, 0);
        draw_line(g2 ,79, 128, 0, 43);
        draw_line(g2 ,79, 147, 0, 73);
        draw_line(g2 ,79, 128, 78, 158);
        draw_line(g2 ,278, 136, 278, 158);
        draw_line(g2 ,347, 124, 347, 154);
        draw_line(g2 ,347, 124, 391, 124);
        draw_line(g2 ,347, 154, 391, 154);
        draw_line(g2 ,99, 164, 138, 200);
        draw_line(g2 ,139, 190, 114, 164);
        draw_line(g2 ,139, 190, 241, 191);
        draw_line(g2 ,137, 205, 239, 205);
        draw_line(g2 ,137, 205, 139, 190);
        draw_line(g2 ,137, 205, 140, 208);
        draw_line(g2 ,140, 208, 228, 208);
        draw_line(g2 ,145, 208, 164, 221);
        draw_line(g2 ,164, 221, 228, 221);
        draw_line(g2, 162, 214, 227, 214);
        draw_line(g2, 162, 214, 154, 208);
        draw_line(g2, 162, 214, 162, 220);
        draw_line(g2, 255, 376, 274, 376);
        draw_line(g2, 255, 376, 255, 361);
        draw_line(g2, 255, 361, 274, 361);
        draw_line(g2, 257, 361, 257, 307);
        draw_line(g2, 256, 307, 274, 307);
        draw_line(g2, 256, 307, 256, 294);
        draw_line(g2, 256, 294, 274, 294);
        draw_line(g2, 257, 294, 257, 181);
        draw_line(g2, 255, 181, 274, 181);
        draw_line(g2, 255, 181, 255, 161);
        draw_line(g2, 83, 164, 251, 167);
        draw_line(g2, 251, 167, 255, 161);
        draw_line(g2, 83, 164, 78, 157);
        draw_line(g2, 251, 167, 251, 183);
        draw_line(g2, 251, 182, 257, 181);
        draw_line(g2, 253, 183, 254, 292);
        draw_line(g2, 256, 294, 253, 291);
        draw_line(g2, 253, 291, 253, 305);
        draw_line(g2, 253, 305, 256, 307);
        draw_line(g2, 254, 305, 254, 356);
        draw_line(g2, 254, 356, 255, 361);
        draw_line(g2, 255, 376, 253, 373);
        draw_line(g2, 253, 373, 253, 356);
        draw_line(g2, 274, 161, 274, 377);
        draw_line(g2, 278, 175, 278, 366);
        draw_line(g2, 351, 110, 322, 139);
        draw_line(g2, 351, 163, 322, 181);
        draw_line(g2, 317, 183, 300, 194);
        draw_line(g2, 318, 142, 300, 160);
        draw_line(g2, 318, 192, 300, 203);
        draw_line(g2, 318, 310, 299, 302);
        draw_line(g2, 351, 326, 322, 313);
        draw_line(g2, 351, 173, 322, 191);
        draw_line(g2, 338, 320, 338, 182);
        draw_line(g2, 335, 318, 335, 183);
        draw_line(g2, 312, 197, 312, 307);
        draw_line(g2, 308, 198, 308, 306);
        draw_line(g2, 295, 195, 284, 203);
        draw_line(g2, 296, 163, 285, 175);
        draw_line(g2, 295, 204, 284, 211);
        draw_line(g2, 296, 300, 284, 294);
        draw_line(g2, 292, 207, 292, 298);
        draw_line(g2, 289, 208, 289, 297);
        draw_line(g2, 338, 172, 338, 125);
        draw_line(g2, 335, 173, 335, 127);
        draw_line(g2, 311, 149, 311, 187);
        draw_line(g2, 308, 152, 308, 188);
        draw_line(g2, 292, 169, 292, 198);
        draw_line(g2, 289, 171, 289, 200);
        //left
        draw_line(g2 ,0, 439, 163, 289);
        draw_line(g2 ,0, 320, 68, 297);
        draw_line(g2 ,0, 329, 69, 304);
        draw_line(g2 ,0, 101, 68, 154);
        draw_line(g2 ,69, 154, 69, 304);
        draw_line(g2 ,0, 166, 22, 176);
        draw_line(g2 ,0, 177, 22, 186);
        draw_line(g2 ,28, 178, 41, 184);
        draw_line(g2 ,27, 188, 41, 194);
        draw_line(g2 ,45, 185, 54, 190);
        draw_line(g2 ,45, 195, 54, 199);
        draw_line(g2 ,57, 191, 68, 196);
        draw_line(g2 ,56, 200, 68, 205);
        draw_line(g2 ,23, 120, 23, 312);
        draw_line(g2 ,27, 123, 27, 311);
        draw_line(g2 ,41, 134, 41, 306);
        draw_line(g2 ,45, 136, 45, 305);
        draw_line(g2 ,54, 144, 54, 301);
        draw_line(g2 ,57, 146, 57, 300);
        draw_line(g2, 460, 48, 507, 12);
        draw_line(g2, 460, 48, 461, 111);
        draw_line(g2, 461, 111, 506, 85);
        draw_line(g2, 507, 12, 506, 85);
        draw_line(g2, 516, 0, 517, 79);
        draw_line(g2, 517, 79, 563, 51);
        draw_line(g2, 506, 0, 506, 86);
        draw_line(g2, 512, 0, 512, 85);
        draw_line(g2, 506, 86, 512, 85);
        draw_line(g2, 512, 85, 516, 79);
        draw_line(g2, 91, 172, 91, 294);
        draw_line(g2, 91, 172, 134, 205);
        draw_line(g2, 91, 294, 134, 280);
        draw_line(g2, 134, 280, 134, 205);
        //กระจกซ้ายใน
        draw_line(g2, 143, 212, 143, 276);
        draw_line(g2, 143, 212, 158, 223);
        draw_line(g2, 143, 276, 158, 271);
        draw_line(g2, 158, 271, 158, 223);
        draw_line(g2, 143, 271, 158, 267);

        draw_line(g2, 145, 213, 145, 271);
        draw_line(g2, 147, 215, 147, 270);

        draw_line(g2, 149, 217, 149, 269);
        draw_line(g2, 151, 218, 151, 269);

        draw_line(g2, 153, 219, 153, 268);
        draw_line(g2, 155, 221, 155, 268);

        draw_line(g2, 143, 231, 145, 233);
        draw_line(g2, 143, 237, 145, 239);

        draw_line(g2, 147, 233, 149, 235);
        draw_line(g2, 147, 239, 149, 241);

        draw_line(g2, 151, 235, 153, 237);
        draw_line(g2, 151, 241, 153, 243);

        draw_line(g2, 155, 237, 157, 239);
        draw_line(g2, 155, 243, 157, 245);
        draw_line(g2 ,91, 288, 133, 275);

        draw_line(g2 ,98, 177, 98, 286);
        draw_line(g2 ,100, 179, 100, 286);

        draw_line(g2 ,105, 184, 105, 284);
        draw_line(g2 ,107, 184, 107, 284);

        draw_line(g2 ,111, 188, 111, 282);
        draw_line(g2 ,113, 189, 113, 282);

        draw_line(g2 ,116, 191, 116, 281);
        draw_line(g2 ,118, 193, 118, 280);

        draw_line(g2 ,121, 195, 121, 279);
        draw_line(g2 ,123, 197, 123, 278);

        draw_line(g2 ,126, 199, 126, 277);
        draw_line(g2 ,128, 201, 128, 276);

        draw_line(g2 ,131, 203, 131, 276);

        draw_line(g2 ,92, 206, 98, 209);
        draw_line(g2 ,92, 212, 98, 215);

        draw_line(g2 ,100, 210, 104, 212);
        draw_line(g2 ,100, 216, 104, 218);

        draw_line(g2 ,108, 214, 110, 215);
        draw_line(g2 ,108, 220, 110, 221);

        draw_line(g2 ,114, 217, 116, 218);
        draw_line(g2 ,113, 223, 116, 224);

        draw_line(g2 ,118, 218, 120, 220);
        draw_line(g2 ,118, 224, 120, 226);

        draw_line(g2 ,124, 222, 126, 224);
        draw_line(g2 ,124, 228, 126, 230);

        draw_line(g2 ,128, 224, 130, 226);
        draw_line(g2 ,128, 230, 130, 232);

        draw_line(g2 ,131, 226, 133, 228);
        draw_line(g2 ,131, 232, 133, 234);
        draw_line(g2, 164, 294, 164, 222);

        //เสาร์สุดท้าย
        draw_line(g2, 219, 300, 219, 293);
        draw_line(g2, 219, 300, 227, 300);
        draw_line(g2, 219, 293, 227, 293);
        draw_line(g2, 227, 300, 227, 293);

        draw_line(g2, 220, 293, 220, 273);
        draw_line(g2, 222, 293, 222, 273);
        draw_line(g2, 221, 293, 221, 300);

        draw_line(g2, 219, 273, 219, 266);
        draw_line(g2, 219, 266, 227, 266);
        draw_line(g2, 227, 266, 227, 273);
        draw_line(g2, 227, 273, 219, 273);

        draw_line(g2, 220, 266, 220, 228);
        draw_line(g2, 222, 266, 222, 228);
        draw_line(g2, 221, 266, 221, 273);

        draw_line(g2, 219, 227, 219, 222);
        draw_line(g2, 219, 227, 227, 227);
        draw_line(g2, 219, 222, 227, 222);
        draw_line(g2, 221, 222, 221, 227);

        draw_line(g2, 227, 222, 227, 293);

        // K-DAI
        draw_line(g2, 353, 130, 353, 146);//k
        draw_line(g2, 353, 138, 358, 146);
        draw_line(g2, 353, 138, 358, 130);

        draw_line(g2, 358, 138, 362, 138);//-

        draw_line(g2, 364, 130, 364, 146);//D
        draw_line(g2, 364, 130, 369, 138);
        draw_line(g2, 364, 146, 369, 138);

        draw_line(g2, 369, 146, 374, 130);//A
        draw_line(g2, 379, 146, 374, 130);
        draw_line(g2, 372, 138, 377, 138);

        draw_line(g2, 381, 146, 386, 146);//I
        draw_line(g2, 383, 146, 383, 130);
        draw_line(g2, 381, 130, 386, 130);

        draw_line(g2, 164, 293, 0, 472);
        draw_line(g2, 164, 294, 219, 294);
        draw_line(g2, 164, 287, 219, 287);
        draw_line(g2, 0, 472, 0, 600);
        // เส้นบนพื้น
        draw_line(g2, 0, 482, 164, 295);
        draw_line(g2, 0, 496, 166, 295);
        draw_line(g2, 0, 508, 168, 295);
        draw_line(g2, 0, 520, 170, 295);

        draw_line(g2, 0, 531, 172, 295);
        draw_line(g2, 0, 543, 174, 295);
        draw_line(g2, 0, 558, 176, 295);
        draw_line(g2, 0, 572, 178, 295);
        draw_line(g2, 0, 587, 180, 295);
        draw_line(g2, 1, 599, 182, 295);
        draw_line(g2, 10, 599, 184, 295);
        draw_line(g2, 19, 599, 186, 295);
        draw_line(g2, 28, 599, 188, 295);
        draw_line(g2, 38, 599, 190, 295);
        draw_line(g2, 47, 599, 191, 295);
        draw_line(g2, 57, 599, 192, 295);
        draw_line(g2, 66, 599, 193, 295);
        draw_line(g2, 75, 599, 194, 295);
        draw_line(g2, 84, 599, 194, 295);
        draw_line(g2, 94, 599, 195, 295);
        draw_line(g2, 103, 599, 195, 295);
        draw_line(g2, 112, 599, 195, 295);
        draw_line(g2, 122, 599, 195, 295);
        draw_line(g2, 131, 599, 195, 295);
        draw_line(g2, 140, 599, 195, 295);
        draw_line(g2, 149, 599, 196, 295);
        draw_line(g2, 158, 599, 196, 295);
        draw_line(g2, 167, 599, 196, 295);
        draw_line(g2, 176, 599, 197, 295);
        draw_line(g2, 185, 599, 198, 295);
        draw_line(g2, 195, 599, 199, 295);
        draw_line(g2, 203, 599, 200, 295);

        draw_line(g2, 213, 599, 200, 295);
        draw_line(g2, 222, 599, 202, 295);
        draw_line(g2, 231, 599, 203, 295);
        draw_line(g2, 240, 599, 204, 295);

        draw_line(g2, 249, 599, 206, 295);
        draw_line(g2, 258, 599, 207, 295);
        draw_line(g2, 267, 599, 208, 295);
        draw_line(g2, 276, 599, 209, 295);

        draw_line(g2, 285, 599, 210, 295);
        draw_line(g2, 294, 599, 211, 295);
        draw_line(g2, 304, 599, 212, 295);
        draw_line(g2, 313, 599, 213, 295);
        draw_line(g2, 322, 599, 214, 295);
        draw_line(g2, 331, 599, 214, 295);

        draw_line(g2, 340, 599, 216, 295);
        draw_line(g2, 349, 599, 218, 295);

        draw_line(g2, 359, 599, 257, 377);
        draw_line(g2, 367, 599, 260, 377);
        draw_line(g2, 376, 599, 263, 377);
        draw_line(g2, 385, 599, 265, 377);
        draw_line(g2, 395, 599, 268, 377);
        draw_line(g2, 404, 599, 271, 377);

        draw_line(g2, 231, 319, 252, 366);
        draw_line(g2, 233, 319, 252, 359);
        draw_line(g2, 235, 319, 252, 352);
        draw_line(g2, 237, 319, 252, 348);
        draw_line(g2, 239, 319, 252, 343);

        draw_line(g2, 222, 301, 228, 313);
        draw_line(g2, 224, 301, 228, 309);
        draw_line(g2, 227, 300, 228, 304);

        draw_line(g2, 412, 599, 401, 581);
        draw_line(g2, 423, 599, 411, 581);
        draw_line(g2, 433, 599, 419, 580);
        draw_line(g2, 442, 599, 427, 579);

        draw_line(g2, 229, 317, 240, 317);
        draw_line(g2, 229, 309, 240, 309);
        draw_line(g2, 229, 317, 229, 309);
        draw_line(g2, 231, 317, 231, 309);

        draw_line(g2, 240, 317, 240, 309);

        draw_line(g2, 229, 317, 228, 310);
        draw_line(g2, 232, 309, 232, 282);
        draw_line(g2, 229, 309, 229, 281);
        draw_line(g2, 228, 281, 239, 281);
        draw_line(g2, 239, 309, 239, 274);
        draw_line(g2, 239, 274, 228, 274);
        draw_line(g2, 228, 274, 228, 281);
        draw_line(g2, 231, 274, 231, 281);

        draw_line(g2, 229, 274, 229, 215);

        draw_line(g2, 229, 215, 239, 215);
        draw_line(g2, 239, 215, 239, 275);
        draw_line(g2, 228, 215, 228, 206);
        draw_line(g2, 231, 215, 231, 206);

        draw_line(g2, 239, 206, 239, 214);

        draw_line(g2, 232, 274, 232, 215);

        //ป้าย
        draw_line(g2, 253, 199, 239, 213);
        draw_line(g2, 253, 188, 239, 206);
        draw_line(g2, 241, 202, 241, 191);

        draw_line(g2, 242, 191, 251, 180);

        draw_line(g2, 240, 317, 253, 335);
        draw_line(g2, 240, 309, 253, 327);

        draw_line(g2, 253, 280, 251, 279);
        draw_line(g2, 253, 290, 251, 289);

        draw_line(g2, 249, 279, 247, 278);
        draw_line(g2, 249, 289, 247, 288);

        draw_line(g2, 244, 278, 241, 277);
        draw_line(g2, 244, 287, 241, 285);

        draw_line(g2, 244, 224, 241, 225);
        draw_line(g2, 244, 216, 241, 218);

        draw_line(g2, 240, 312, 240, 212);
        draw_line(g2, 244, 316, 244, 208);

        draw_line(g2, 246, 316, 246, 222);
        draw_line(g2, 249, 321, 249, 224);
        draw_line(g2, 251, 323, 251, 224);

        draw_line(g2, 251, 215, 251, 202);
        draw_line(g2, 249, 215, 249, 203);
        draw_line(g2, 246, 215, 246, 206);

        //ป้ายติดเสา 2
        draw_line(g2, 245, 223, 253, 223);
        draw_line(g2, 246, 222, 252, 222);

        draw_line(g2, 245, 215, 253, 215);
        draw_line(g2, 246, 216, 252, 216);

        draw_line(g2, 245, 215, 245, 223);
        draw_line(g2, 246, 216, 246, 222);

        //ไฟด้านบน ดวงด้านหน้า
        draw_line(g2, 220, 96, 298, 100);
        draw_line(g2, 220, 96, 211, 95);
        draw_line(g2, 220, 97, 298, 101);
        draw_line(g2, 220, 97, 213, 98);
        draw_line(g2, 213, 98, 208, 99);
        draw_line(g2, 208, 100, 140, 97);
        draw_line(g2, 140, 97, 140, 90);
        draw_line(g2, 140, 90, 206, 93);
        draw_line(g2, 206, 93, 213, 95);
        draw_line(g2, 206, 107, 206, 100);
        draw_line(g2, 206, 107, 143, 106);
        draw_line(g2, 143, 106, 142, 103);
        draw_line(g2, 143, 98, 142, 103);
        draw_line(g2, 142, 102, 205, 104);
        draw_line(g2, 298, 100, 300, 109);

        //หลอดไฟด้านใน
        draw_line(g2, 246, 183, 247, 188);
        draw_line(g2, 246, 183, 174, 181);
        draw_line(g2, 174, 181, 174, 185);
        draw_line(g2, 204, 185, 174, 185);
        draw_line(g2, 204, 185, 205, 182);
        draw_line(g2, 204, 187, 174, 187);
        draw_line(g2, 204, 187, 204, 185);
        draw_line(g2, 174, 187, 174, 185);
        draw_line(g2, 246, 184, 205, 184);

        //เติมเส้น
        draw_line(g2, 417, 0, 417, 43);
        draw_line(g2, 440, 360, 440, 389);

        //น้ำตาลเข้ม ขอบล่างฝั่งขวา
        buffer = floodFill(buffer, 374, 361, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 338, 339, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 312, 319, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 291, 309, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 279, 302, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 55, 402, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 32, 94, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 123, 180, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 155, 211, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 201, 292, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 362, 72, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 336, 462, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 248, 325, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 265, 299, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 254, 299, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 265, 368, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 254, 368, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 264, 172, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 254, 172, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 436, 565, Color.WHITE, new Color(152,107,65,255).darker());
        buffer = floodFill(buffer, 435, 376, Color.WHITE, new Color(182,142,101,255).darker());
        buffer = floodFill(buffer, 426, 23, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 463, 25, Color.WHITE, new Color(86,52,42,255));
        buffer = floodFill(buffer, 409, 23, Color.WHITE, new Color(86,52,42,255));
        buffer = floodFill(buffer, 450, 376, Color.WHITE, new Color(182,142,101,255).darker());
        buffer = floodFill(buffer, 445, 565, Color.WHITE, new Color(152,107,65,255).darker());

        //สีกำแพงขวา
        buffer = floodFill(buffer, 81, 338, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 375, 234, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 366, 418, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 339, 393, Color.WHITE, new Color(241,195,167,255));    // 241,195,167,255
        buffer = floodFill(buffer, 307, 367, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 292, 346, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 281, 331, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 378, 106, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 280, 280, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 427, 425, Color.WHITE, new Color(241,195,167,180).darker()); //---------+-+
        buffer = floodFill(buffer, 426, 249, Color.WHITE, new Color(241,195,167,180).darker()); //---------+-+
        buffer = floodFill(buffer, 448, 470, Color.WHITE, new Color(241,195,167,200).darker());
        buffer = floodFill(buffer, 465, 123, Color.WHITE, new Color(241,195,167,200).darker());
        buffer = floodFill(buffer, 277, 232, Color.WHITE, new Color(241,195,167,255));
                //กำแพงตรงกลาง
        buffer = floodFill(buffer, 252, 308, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 247, 294, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 243, 297, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 243, 253, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 248, 251, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 253, 250, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 248, 202, Color.WHITE, new Color(152,107,65,255));  //<----------------- ขอบไม้ด้านบนกำแแพง(ฝั่งขวา) ตรงกลาง
        //ขอบไม้แนวนอนกระจกขวา
        buffer = floodFill(buffer, 338, 179, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 309, 194, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 291, 206, Color.WHITE, new Color(182,142,101,255));

        //เพดาน
        buffer = floodFill(buffer, 120, 64, Color.WHITE, new Color(255,195,164,255).darker());   //201,165,133,255
        buffer = floodFill(buffer, 158, 181, Color.WHITE, new Color(255,195,164,255).darker());
        buffer = floodFill(buffer, 172, 210, Color.WHITE, new Color(255,195,164,255).darker());

        //ไม้รอยต่อแนวตั้งขวา
        buffer = floodFill(buffer, 354, 344, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 354, 120, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 320, 327, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 298, 197, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 283, 302, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 397, 423, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 408, 347, Color.WHITE, new Color(86,52,42,255));
                //ด้านหลัง
        buffer = floodFill(buffer, 249, 184, Color.WHITE, new Color(148, 147, 145,170));
        buffer = floodFill(buffer, 323, 87, Color.WHITE, new Color(148, 147, 145,170));
        buffer = floodFill(buffer, 228, 246, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 228, 289, Color.WHITE, new Color(152,107,65,255));

        //ประตู
        buffer = floodFill(buffer, 478, 469, Color.WHITE, new Color(152,107,65,225).darker()); // 91 41 6 200
        buffer = floodFill(buffer, 536, 421, Color.WHITE, new Color(152,107,65,225).darker());

        //สี่เหลี่ยมบนเพดาน
        buffer = floodFill(buffer, 185, 148, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 201, 164, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 201, 206, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 201, 200, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 203, 219, Color.WHITE, new Color(152,107,65,255));

        //ไฟ
        buffer = floodFill(buffer, 185, 101, Color.WHITE, new Color(192,192,192,220));
        buffer = floodFill(buffer, 190, 183, Color.WHITE, new Color(159,147,142,255));
        buffer = floodFill(buffer, 185, 95, Color.WHITE, new Color(159,147,142,255));
        buffer = floodFill(buffer, 185, 105, Color.WHITE, new Color(159,147,142,255));
        buffer = floodFill(buffer, 190, 186, Color.WHITE, new Color(192,192,192,220));
        buffer = floodFill(buffer, 211, 183, Color.WHITE, new Color(0,0,0,255).brighter().brighter());
        buffer = floodFill(buffer, 505, 410, Color.WHITE, new Color(0,0,0,255).brighter().brighter());

        //กระจกซ้ายใน
        buffer = floodFill(buffer, 8, 175, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 34, 188, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 48, 191, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 62, 197, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 97, 212, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 102, 216, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 108, 216, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 114, 218, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 119, 220, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 125, 224, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 129, 226, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 132, 228, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 144, 233, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 148, 235, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 152, 237, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 156, 239, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 104, 287, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 149, 271, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 12, 320, Color.WHITE, new Color(152,107,65,255));

        //ขอบแนวตั้งกระจกซ้าย
        buffer = floodFill(buffer, 25, 180, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 43, 186, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 56, 193, Color.WHITE, new Color(182,142,101,255));
        //-------------------------------------------------------------------------
        buffer = floodFill(buffer, 99, 240, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 106, 240, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 112, 237, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 117, 237, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 122, 237, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 127, 237, Color.WHITE, new Color(182,142,101,255));
        //--------------------------------------------------------------------------
        buffer = floodFill(buffer, 146, 234, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 150, 234, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 154, 234, Color.WHITE, new Color(182,142,101,255));

        //เสาขวา (เสาแรก)
        buffer = floodFill(buffer, 263, 237, Color.WHITE, new Color(241,195,167,205));
        buffer = floodFill(buffer, 265, 335, Color.WHITE, new Color(241,195,167,205));
        buffer = floodFill(buffer, 255, 335, Color.WHITE, new Color(241,195,167,255)); // 214 181 158 255
        buffer = floodFill(buffer, 255, 237, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 255, 237, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 585, 318, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 564, 599, Color.WHITE, new Color(241,195,167,255));

        // เสาขวาตรงกลาง
        buffer = floodFill(buffer, 238, 220, Color.WHITE, new Color(241,195,167,205));
        buffer = floodFill(buffer, 238, 282, Color.WHITE, new Color(241,195,167,205));
        buffer = floodFill(buffer, 230, 238, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 230, 291, Color.WHITE, new Color(241,195,167,255));
                //ขอบเสา
        buffer = floodFill(buffer, 234, 276, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 230, 276, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 232, 208, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 229, 208, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 234, 310, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 230, 310, Color.WHITE, new Color(182,142,101,255));
                // เสาขวาหลังสุด
        buffer = floodFill(buffer, 223, 240, Color.WHITE, new Color(241,195,167,205));
        buffer = floodFill(buffer, 223, 282, Color.WHITE, new Color(241,195,167,205));
        buffer = floodFill(buffer, 221, 242, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 221, 291, Color.WHITE, new Color(241,195,167,255));
                //ขอบเสา
        buffer = floodFill(buffer, 222, 224, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 220, 223, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 222, 269, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 220, 269, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 222, 295, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 220, 295, Color.WHITE, new Color(182,142,101,255));

        //ขอบไม้ (ขวา)
        buffer = floodFill(buffer, 222, 224, Color.WHITE, new Color(152,107,65,255));
        buffer = floodFill(buffer, 241, 279, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 245, 284, Color.WHITE, new Color(152,107,65,255)); //-----------
        buffer = floodFill(buffer, 245, 213, Color.WHITE, new Color(152,107,65,255)); //-----------++
        buffer = floodFill(buffer, 247, 284, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 250, 284, Color.WHITE, new Color(152,107,65,255)); //-----------
        buffer = floodFill(buffer, 250, 213, Color.WHITE, new Color(152,107,65,255)); //-----------++
        buffer = floodFill(buffer, 252, 280, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 242, 221, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 566, 566, Color.WHITE, new Color(182,142,101,255));
        buffer = floodFill(buffer, 568, 518, Color.WHITE, new Color(152,107,65,255));

        buffer = floodFill(buffer, 287, 170, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 305, 153, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 337, 120, Color.WHITE, new Color(241,195,167,255));

        buffer = floodFill(buffer, 293, 299, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 300, 303, Color.WHITE, new Color(241,195,167,255));
        buffer = floodFill(buffer, 330, 320, Color.WHITE, new Color(241,195,167,255));

        //ขอบแนวตั้งกระจกขวา
        buffer = floodFill(buffer, 337, 254, Color.WHITE, new Color(215,186,137,255).brighter());
        buffer = floodFill(buffer, 337, 148, Color.WHITE, new Color(215,186,137,255).brighter());
        buffer = floodFill(buffer, 311, 272, Color.WHITE, new Color(215,186,137,255).brighter());
        buffer = floodFill(buffer, 310, 174, Color.WHITE, new Color(215,186,137,255).brighter());
        buffer = floodFill(buffer, 291, 264, Color.WHITE, new Color(215,186,137,255).brighter());
        buffer = floodFill(buffer, 291, 175, Color.WHITE, new Color(215,186,137,255).brighter());
        buffer = floodFill(buffer, 509, 61, Color.WHITE, new Color(215,186,137,255));
        buffer = floodFill(buffer, 515, 61, Color.WHITE, new Color(182,142,101,255).darker());

        //กระจก
        buffer = floodFill(buffer, 537, 305, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 481, 298, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 495, 71, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 540, 29, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 346, 248, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 332, 269, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 344, 148, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 330, 157, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 315, 245, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 316, 171, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 307, 265, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 307, 175, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 294, 244, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 294, 185, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 286, 264, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 286, 185, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 252, 213, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 248, 213, Color.WHITE, new Color(44,74,100,255).brighter());
        buffer = floodFill(buffer, 243, 213, Color.WHITE, new Color(44,74,100,255).brighter());

        //ซ้ายกระจก
        buffer = floodFill(buffer, 12, 253, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 8, 149, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 35, 244, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 33, 161, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 48, 251, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 47, 163, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 62, 245, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 61, 174, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());

        buffer = floodFill(buffer, 97, 250, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 97, 196, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 104, 245, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 104, 196, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 109, 203, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 109, 244, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 133, 244, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 133, 217, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 129, 217, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 129, 244, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 125, 244, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 125, 217, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 119, 240, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 119, 217, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 115, 240, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 115, 217, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());

        buffer = floodFill(buffer, 144, 245, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 144, 221, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 148, 221, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 148, 244, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 152, 244, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 152, 221, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 156, 245, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());
        buffer = floodFill(buffer, 156, 233, Color.WHITE, new Color(44,74,100,255).brighter().brighter().brighter());

        //กำแพงหลัง
        buffer = floodFill(buffer, 192, 264, Color.WHITE, new Color(241,195,167,200).darker());

        //ป้าย
        buffer = floodFill(buffer, 365, 142, Color.WHITE, new Color(127,91,93,255).brighter());
        buffer = floodFill(buffer, 366, 150, Color.WHITE, new Color(127,91,93,255).brighter());
        buffer = floodFill(buffer, 374, 132, Color.WHITE, new Color(127,91,93,255).brighter());
        buffer = floodFill(buffer, 366, 153, Color.WHITE, new Color(127,91,93,255).brighter());
        buffer = floodFill(buffer, 396, 153, Color.WHITE, new Color(127,91,93,255).brighter());
        buffer = floodFill(buffer, 251, 218, Color.WHITE, new Color(127,91,93,255).brighter());//ป้ายใน

        // พื้น!!!!
        int Round = 0;
        for(int y = 294; y < 600; y++){
                for(int x = 162-Round; x < 275+Round; x++){
        buffer = floodFill(buffer, x, y, Color.WHITE, new Color(238,221,155,255));
                }
        if(Round < 162) Round++;
        }
        buffer = floodFill(buffer, 410, 587, new Color(238,221,155,255), new Color(238,221,155,255).darker());
        buffer = floodFill(buffer, 416, 587, new Color(238,221,155,255), new Color(238,221,155,255).darker());
        buffer = floodFill(buffer, 425, 587, new Color(238,221,155,255), new Color(238,221,155,255).darker());
        buffer = floodFill(buffer, 436, 587, new Color(238,221,155,255), new Color(238,221,155,255).darker());

        bezier(g2, 300, 106, 310, 20, 400, 30, 362, 0, 1);

        g.drawImage(buffer, 0, 0, null);

    }
    public void draw_line (Graphics g ,int x1 ,int y1 ,int x2 ,int y2){
        g.drawLine(x1, y1, x2, y2);
    }


    public BufferedImage floodFill(BufferedImage m ,int x ,int y ,Color target_Color ,Color replacement_Color){
        Queue<Point> q = new LinkedList<Point>();
        Graphics2D g2 = m.createGraphics();

        if(new Color(m.getRGB(x ,y)).equals(target_Color)){
            g2.setColor(replacement_Color);
            plot(g2 ,x ,y ,1);
            q.add(new Point(x ,y));
        }

        while (!q.isEmpty()){
            Point p = q.poll();
            //south
            if(p.y < 600 && new Color(m.getRGB(p.x ,p.y + 1)).equals(target_Color)){
                g2.setColor(replacement_Color);
                plot(g2 ,p.x ,p.y + 1 ,1);
                q.add(new Point(p.x ,p.y + 1));
            }
            //north
            if(p.y > 0 && new Color(m.getRGB(p.x ,p.y - 1)).equals(target_Color)){
                g2.setColor(replacement_Color);
                plot(g2 ,p.x ,p.y - 1 ,1);
                q.add(new Point(p.x ,p.y - 1));
            }
            //east
            if(p.x < 600 && new Color(m.getRGB(p.x + 1 ,p.y)).equals(target_Color)){
                g2.setColor(replacement_Color);
                plot(g2 ,p.x + 1 ,p.y ,1);
                q.add(new Point(p.x + 1 ,p.y));
            }
            //west
            if(p.x > 0 && new Color(m.getRGB(p.x - 1 ,p.y)).equals(target_Color)){
                g2.setColor(replacement_Color);
                plot(g2 ,p.x - 1 ,p.y ,1);
                q.add(new Point(p.x -1 ,p.y));
            }
        }
    return m;
    }

    public void bezier(Graphics g, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4 , int s) {
        for (int i = 0; i <= 1000; i++) {
            double t = i / 1000.0;

            int x = (int) (Math.pow((1 - t), 3) * x1 + 3 * t * Math.pow((1 - t), 2) * x2 + 3 * t * t * (1 - t) * x3
                    + t * t * t * x4);
            int y = (int) (Math.pow((1 - t), 3) * y1 + 3 * t * Math.pow((1 - t), 2) * y2 + 3 * t * t * (1 - t) * y3
                    + t * t * t * y4);

            plot(g, x, y, s);
        }
    }

    public void plot (Graphics g ,int x ,int y ,int size){
        g.fillRect(x, y, size, size);
    }
}