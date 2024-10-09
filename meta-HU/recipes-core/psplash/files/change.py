from PIL import Image
import sys

def image_to_rle(image_path):
    img = Image.open(image_path)
    img = img.convert("RGBA")  # RGBA 포맷으로 변환
    pixels = list(img.getdata())
    rle_data = []
    prev_pixel = None
    count = 0

    for pixel in pixels:
        if pixel == prev_pixel and count < 255:
            count += 1
        else:
            if prev_pixel is not None:
                rle_data.append((count, prev_pixel))
            prev_pixel = pixel
            count = 1
    rle_data.append((count, prev_pixel))  # 마지막 픽셀 추가

    # C 헤더 파일로 변환
    c_data = []
    for count, (r, g, b, a) in rle_data:
        c_data.append(f'\\{count}\\{r}\\{g}\\{b}\\{a}')

    with open("output_img.h", "w") as f:
        f.write('#define POKY_IMG_ROWSTRIDE (2280)\n')
        f.write('#define POKY_IMG_WIDTH (570)\n')
        f.write('#define POKY_IMG_HEIGHT (720)\n')
        f.write('#define POKY_IMG_BYTES_PER_PIXEL (4) /* 3:RGB, 4:RGBA */\n')
        f.write('#define POKY_IMG_RLE_PIXEL_DATA ((uint8*) \\\n  "' + "".join(c_data) + '")\n')

# 이미지 경로 지정 후 실행
image_to_rle("psplash-raspberrypi-img.png")
