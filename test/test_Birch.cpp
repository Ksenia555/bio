#include "Cell.h"
#include "Animals.h"
#include "Eukaryotes.h"
#include "Plants.h"
#include "Prokaryotes.h"
#include "Staphylococcus.h"
#include "Vibrions.h"

#include <gtest.h>

TEST(TAnimals, can_create_plant_cell_with_positive_parameter)
{
  ASSERT_NO_THROW(TAnimals animals(12));
}

TEST(TPlants, can_create_animal_cell_with_positive_parameter)
{
  ASSERT_NO_THROW(TPlants plants(12));
}

TEST(TStaphylococcus, can_create_staphylococcus_with_positive_parameter)
{
  ASSERT_NO_THROW(TStaphylococcus staphylococcus(12));
}

TEST(TVibrions, can_create_vibrions_with_positive_parameter)
{
  ASSERT_NO_THROW(TVibrions vibrions(12));
}

TEST(TAnimals, can_get_mitochondria)
{
  TAnimals animals(3);

  EXPECT_NEAR(3, animals.GetMitochondria(), 0.000001);
}

TEST(TPlants, can_get_plastid)
{
  TPlants plants(3);

  EXPECT_NEAR(3, plants.GetPlastids(), 0.000001);
}

TEST(TStaphylococcus, can_get_cell_coccus)
{
  TStaphylococcus staphylococcus(3);

  EXPECT_NEAR(3, staphylococcus.GetCellCoccus(), 0.000001);
}

TEST(TVibrions, can_get_length)
{
  TVibrions vibrions(3);

  EXPECT_NEAR(3, vibrions.GetLength(), 0.000001);
}

TEST(TAnimals, can_copy)
{
  TAnimals animals(8);
  TAnimals an(animals);
}

TEST(TPlants, can_copy)
{
  TPlants plants(8);
  TPlants pl(plants);
}

TEST(TStaphylococcus, can_copy)
{
  TStaphylococcus staphylococcus(8);
  TStaphylococcus sthp(staphylococcus);
}

TEST(TVibrions, can_copy)
{
  TVibrions vibrions(8);
  TVibrions vib(vibrions);
}

