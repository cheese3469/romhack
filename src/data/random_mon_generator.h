// Pool settings for random mon generation via scripts. For more info on options, check out
// struct RandomSpeciesGeneratorOptions and struct RandomItemGeneratorOptions in src/random_mon_generation.c.

#include "constants/random_mon_generation.h"

static const enum Species sRandomSpeciesNormanGiftSpeciesPool[] =
{
    SPECIES_PHANPY,
    SPECIES_AIPOM,
    SPECIES_GLIGAR,
};

static const struct RandomSpeciesGeneratorOptions sRandomSpeciesGeneratorOptions[] =
{
    [SPECIES_GENERATOR_NORMAN_GIFT] =
    {
        .speciesPool = sRandomSpeciesNormanGiftSpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesNormanGiftSpeciesPool),
    },
};

static const struct RandomItemGeneratorOptions sRandomItemGeneratorOptions[RANDOM_ITEM_OPTIONS_COUNT] =
{
};
