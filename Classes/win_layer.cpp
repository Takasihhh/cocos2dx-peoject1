#include"win_layer.h"
#include "Game_data.h"
#include"BigLevelScene.h"
#include "Gamescene.h"

win_layer * win_layer::create(int xingxingnum)
{
	win_layer *layer = new win_layer();


	int p = 0;
	if (layer && layer->InitWinLayer(xingxingnum))
	{
		layer->autorelease();
		p++;
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return NULL;
}

bool win_layer::InitWinLayer(int xingxingnum)
{

	if (!Layer::init())
	{

		return false;
	}
	pDirector = Director::getInstance();
	if (1 == Game_data::s_iCurBigLevel || 1 == Game_data::s_iCurBigLevel || 3 == Game_data::s_iCurBigLevel)
	{
		if (Game_data::s_iCurSmallLevel <= 4)
		{

			LayerColor *colorlayer = LayerColor::create(
				Color4B(0, 0, 0, 99),
				winSize.width, winSize.height
				);
			addChild(colorlayer);
			Sprite *bg = Sprite::create("BgWin.png");
			this->addChild(bg);
			bg->setPosition(Vec2(1334.0 / 2, 768.0/ 2));
			for (int i = 0; i < m_xingxingNum; ++i)
			{
				Sprite *xingxing_sp = Sprite::create("xingxing_2.png");
				xingxing_sp->setPosition(Vec2::ZERO);
				xingxing_sp->setScale(1.5f);
				this->addChild(xingxing_sp);
				xingxing_sp->runAction(
					Sequence::create(DelayTime::create(0.3f*(i + 1)),
					Spawn::create(ScaleTo::create(0.2f, 1.2f),
					RotateTo::create(0.2f, 360),
					MoveTo::create(0.2f, Vec2(winSize.width / 2 - 74 + i*86.5, winSize.height / 2 + 63)), NULL),
					ScaleTo::create(0.3f, 1.0f), NULL));

			}
		
			MenuItemImage * nextItemSprite = MenuItemImage::create("botton_Next level1.png",
				"botton_Next level2.png",
				CC_CALLBACK_1(win_layer::Next, this));
			MenuItemImage * replayItemSprite = MenuItemImage::create("botton_Restart1.png",
				"botton_Restart2.png",
				CC_CALLBACK_1(win_layer::Replay, this));
			MenuItemImage * backItemSprite = MenuItemImage::create("Checkpoint selection_1.png",
				"Checkpoint selection_2.png",
				CC_CALLBACK_1(win_layer::Back, this));
			m_menu = Menu::create(nextItemSprite, replayItemSprite, backItemSprite, NULL);
			m_menu->setPosition(Vec2::ZERO);

			nextItemSprite->setPosition(1334 / 2, 340);
			replayItemSprite->setPosition(1334 / 2, 280);
			backItemSprite->setPosition(1334 / 2, 220);

			nextItemSprite->setScaleX(1.22f);
			replayItemSprite->setScale(1.0f);
			backItemSprite->setScale(1.0f);

			this->addChild(m_menu);
			m_menu->setSwallowsTouches(true);

			this->setTouchEnabled(true);
		}
		else if (5 == Game_data::s_iCurSmallLevel)
		{
			m_xingxingNum = xingxingnum;
			winSize = Director::getInstance()->getWinSize();

			LayerColor* colorLayer =
				LayerColor::create(
				ccc4(0, 0, 0, 99),
				winSize.width, winSize.height);
			addChild(colorLayer);

			Sprite* bg = Sprite::create("BgWin.png");
			this->addChild(bg);
			bg->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
			for (int i = 0; i<m_xingxingNum; i++)
			{
				Sprite* spXingxing = Sprite::create("xingxing_2.png");
				spXingxing->setPosition(Vec2::ZERO);
				spXingxing->setScale(1.5f);
				this->addChild(spXingxing);
				spXingxing->runAction(
					Sequence::create(DelayTime::create(0.3f*(i + 1)),
					Spawn::create(ScaleTo::create(0.2f, 1.2f),
					RotateTo::create(0.2f, 360),
					MoveTo::create(0.2f, Vec2(winSize.width / 2 - 74 + i*86.5, winSize.height / 2 + 63)), NULL),
					ScaleTo::create(0.3f, 1.0f), NULL));
			}
			MenuItemImage * replayItemSprite = MenuItemImage::create("botton_Restart1.png",
				"botton_Restart2.png",
				this,
				menu_selector(win_layer::Replay));
			MenuItemImage * backItemSprite = MenuItemImage::create("Checkpoint selection_1.png",
				"Checkpoint selection_2.png",
				this,
				menu_selector(win_layer::Back));
			m_menu = Menu::create(replayItemSprite, backItemSprite, NULL);
			m_menu->setPosition(Vec2::ZERO);
			replayItemSprite->setPosition(1334 / 2, 280);
			backItemSprite->setPosition(1334 / 2, 220);
			replayItemSprite->setScale(1.0f);
			backItemSprite->setScale(1.0f);
			this->addChild(m_menu);
			m_menu->setSwallowsTouches(true);
			this->setTouchEnabled(true);
		}
	}
	return true;

}
bool win_layer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	Point touchPoint = pTouch->getLocationInView();
	touchPoint = Director::getInstance()->convertToGL(touchPoint);

	return true;
}

void win_layer::Back(Ref* obj)
{
	removeFromParentAndCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(0.8f, BigLevelScene::createScene()));
}
void win_layer::Replay(Ref* obj)
{
	removeFromParentAndCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(1.0f, BigLevelScene::createScene()));
}
void win_layer::Next(Ref* obj)
{
	Game_data::s_iCurSmallLevel += 1;
	Director::getInstance()->replaceScene(TransitionFade::create(1.0f, Gamescene::createScene()));
}