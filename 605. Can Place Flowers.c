bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
    int counter = 0;

    for (int i = 0; i < flowerbedSize; ++i)
    {
        if (flowerbed[i] == 0)
        {
            bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
            bool rightEmpty = (i == flowerbedSize - 1) || (flowerbed[i + 1] == 0);

            if (leftEmpty && rightEmpty)
            {
                flowerbed[i] = 1;
                counter++;

                i++;
            }
        }
        else
            i++;
    }

    return counter >= n;
}