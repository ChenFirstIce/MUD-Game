#pragma once
template< typename type >
type& extract(istream& s, type& t) {//����ID��ǩ�ļ��أ��������ƺ͸�����Ʒ��IDΪ0����
	s >> t;
	return t;
}