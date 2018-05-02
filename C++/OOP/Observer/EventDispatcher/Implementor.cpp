typedef std::vector<Button>::iterator ButtonIter;

MenuState::MenuState(): mButtonListener(this)
{
	for(  int i = 0; i != 10; i++ )
	{
		mPreferences.push_back( Button(i) );
	}
	
	//add listeners
	for( ButtonIter b = mPreferences.begin(); b != mPreferences.end(); b++ )
	{
		b->addListener( &mButtonListener );
	}
}