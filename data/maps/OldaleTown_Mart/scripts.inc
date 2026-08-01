OldaleTown_Mart_MapScripts::
	.byte 0

OldaleTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	goto_if_eq VAR_MART_TUTORIAL, 0, OldaleTown_Mart_EventScript_MartTutorial
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	pokemartlistend

OldaleTown_Mart_ExpandedItems::
	pokemart OldaleTown_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	pokemartlistend

OldaleTown_Mart_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock::
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy::
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_Text_PokeBallsAreSoldOut:
	.string "The clerk says they're all sold out.\n"
	.string "I can't buy any POKé BALLS.$"

OldaleTown_Mart_Text_ImGoingToBuyPokeBalls:
	.string "I'm going to buy a bunch of POKé BALLS\n"
	.string "and catch a bunch of POKéMON!$"

OldaleTown_Mart_Text_RestoreHPWithPotion:
	.string "If a POKéMON gets hurt and loses its HP\n"
	.string "and faints, it won't be able to battle.\p"
	.string "To prevent your POKéMON from fainting,\n"
	.string "restore its HP with a POTION.$"

OldaleTown_Mart_EventScript_MartTutorial::
	setvar VAR_MART_TUTORIAL, 1
	msgbox OldaleTown_Mart_Text_ShouldIExplain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OldaleTown_Mart_EventScript_Explain
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Explain::
	msgbox OldaleTown_Mart_Text_HowMartsWork, MSGBOX_DEFAULT
	waitmessage
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_Text_ShouldIExplain:
	.string "Hello! It looks like this is your\n"
	.string "first time visiting a POKéMON MART!\p"
	.string "Should I explain how a POKéMON\n"
	.string "MART works?$"

OldaleTown_Mart_Text_HowMartsWork:
	.string "First, you can get items for catching\n"
	.string "and healing POKéMON.\p"
	.string "We give those items away for free to\n"
	.string "encourage trainers to catch POKéMON\l"
	.string "and battle with other trainers!\p"
	.string "Because of this, we don't buy supplies\n"
	.string "from trainers.\p"
	.string "But we are still a business, so we do\n"
	.string "have premium items that you can buy.\p"
	.string "If you see a second associate in the\n"
	.string "shop, they will offer some exclusive\l"
	.string "items for you to buy.\p"
	.string "And one last thing - we've standardized\n"
	.string "the amount that POKéMON trainers pay\l"
	.string "after a battle. There are a select few\l"
	.string "exceptions, but expect to always get\l"
	.string "the same amount of prize money.\p"
	.string "This helps us curate our item selection\n"
	.string "and prices fairly.\p"
	.string "With that out of the way, I'm sure you\n"
	.string "are eager to get some items.$"
