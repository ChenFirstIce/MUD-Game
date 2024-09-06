#pragma once
template< typename type >
type& extract(istream& s, type& t) {//管理ID标签的加载，加载名称和各个物品，ID为0结束
	s >> t;
	return t;
}